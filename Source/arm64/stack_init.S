// stack_init.S - Configura stack pointer final

.global stack_init
stack_init:
    ldr sp, =0x80000000   // Stack principal do kernel
    ret
