#include <stdarg.h>
#include <stdint.h>

#define DBGU_BASE  0xFFFFF200
#define DBGU_SR    (*(volatile uint32_t*)(DBGU_BASE + 0x14))
#define DBGU_RHR   (*(volatile uint32_t*)(DBGU_BASE + 0x18))
#define DBGU_THR   (*(volatile uint32_t*)(DBGU_BASE + 0x1C))

#define SR_RXRDY (1u<<0)
#define SR_TXRDY (1u<<1)


/*
Send one character through the serial port.
Waits until the transmitter is ready, then writes the character to the THR register.
*/
static void serial_send_char(unsigned char c) {
    while (!(DBGU_SR & SR_TXRDY)) {}
    DBGU_THR = c;
}


/*
Read one character from the serial port.
Waits until data is available, then returns the received byte.
*/
static unsigned char serial_read_char(void) {
    while (!(DBGU_SR & SR_RXRDY)) {}
    return (unsigned char)DBGU_RHR;
}


/*
Send a string over serial by sending each character one by one.
Stops when the null terminator is reached.
*/
static void serial_send_string(const char *s) {
    while (*s) serial_send_char((unsigned char)*s++);
}


/*
A simple printf-like function that supports:
%c (char), %s (string), %x (hex), and %p (pointer).
It sends formatted text over the serial connection.
*/
static int my_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    for (const char *p = fmt; *p; ++p) {
        if (*p != '%') { serial_send_char((unsigned char)*p); continue; }
        ++p;
        switch (*p) {
        case 'c': {
            int c = va_arg(ap, int);
            serial_send_char((unsigned char)c);
            break;
        }
        case 's': {
            const char *s = va_arg(ap, const char*);
            serial_send_string(s ? s : "(null)");
            break;
        }
        case 'p': {
            char b[17];
            serial_send_string("0x");
            serial_send_string(b);
            break;
        }
        default:
            serial_send_char('%');
            serial_send_char((unsigned char)*p);
            break;
        }
    }
    va_end(ap);
    return 0;
}


/*
Main loop.
Waits for characters from the serial input.
Every received character is printed back with a message.
*/
int main(void) {
    serial_send_string("Ready\r\n");
    for (;;) {
        unsigned char c = serial_read_char();
        my_printf("Received character: '%c'\r\n", (int)c);
    }
}
