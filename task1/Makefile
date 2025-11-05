CC = arm-none-eabi-gcc

OUT = serial_demo.elf
SRC = start.s serial_demo.c

CFLAGS = -std=c99 -mcpu=arm920t -ffreestanding -nostdlib
LDFLAGS = -Wl,-Ttext=0x20000000 -Wl,-e,_start

QEMU = qemu-bsprak
QEMUFLAGS = -M portux920t -nographic -serial stdio -monitor none -kernel $(OUT)

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

run: $(OUT)
	$(QEMU) $(QEMUFLAGS)

clean:
	rm -f $(OUT)
