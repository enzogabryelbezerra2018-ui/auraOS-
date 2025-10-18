// memory_init.S - Inicializa MMU, cache e tabela de páginas

.global memory_init
memory_init:
    mrs x0, sctlr_el1
    bic x0, x0, #1        // Desabilita MMU
    msr sctlr_el1, x0

    ldr x1, =0x400000      // Endereço TTBR0_EL1
    msr ttbr0_el1, x1

    mrs x0, sctlr_el1
    orr x0, x0, #1         // Habilita MMU
    msr sctlr_el1, x0

    ret
