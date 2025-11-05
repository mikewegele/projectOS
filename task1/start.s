.section .text
.global _start
.extern main

.equ STACK_TOP, 0x20040000

_start:
    ldr sp, =STACK_TOP
    bl  main
1:  b   1b
