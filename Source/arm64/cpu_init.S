// cpu_init.S - Inicialização completa da CPU ARM64 para AuraOS

.global cpu_init
cpu_init:

    // Parte 1: Inicializa x0-x15 e x16-x18
    mov x0, #0
    mov x1, #0
    mov x2, #0
    mov x3, #0
    mov x4, #0
    mov x5, #0
    mov x6, #0
    mov x7, #0
    mov x8, #0
    mov x9, #0
    mov x10, #0
    mov x11, #0
    mov x12, #0
    mov x13, #0
    mov x14, #0
    mov x15, #0
    mov x16, #0
    mov x17, #0
    mov x18, #0

    // Parte 2: Inicializa x19-x30 e stack temporário
    mov x19, #0
    mov x20, #0
    mov x21, #0
    mov x22, #0
    mov x23, #0
    mov x24, #0
    mov x25, #0
    mov x26, #0
    mov x27, #0
    mov x28, #0
    mov x29, #0
    mov x30, #0
    ldr sp, =0x80000000

    // Parte 3: Inicializa MMU e cache, chama stack_init
    mrs x0, sctlr_el1
    bic x0, x0, #1
    msr sctlr_el1, x0
    ldr x1, =0x400000
    msr ttbr0_el1, x1
    mrs x0, sctlr_el1
    orr x0, x0, #1
    msr sctlr_el1, x0

    bl stack_init

    // Parte 4: Vetores de exceção e bootloader
    bl exception_vectors
    bl auraOS_bootloader

1:  b 1b
