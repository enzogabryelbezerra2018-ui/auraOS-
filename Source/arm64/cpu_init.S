// cpu_init.S - Inicialização completa da CPU ARM64 para AuraOS
// Integra todas as partes: registradores, stack, MMU, cache, vetores e bootloader

.global cpu_init
cpu_init:

    // ===============================
    // Parte 1: Inicializa registradores x0-x15 e x16-x18
    // ===============================
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
    // Fim Parte 1

    // ===============================
    // Parte 2: Inicializa registradores x19-x30 e stack temporário
    // ===============================
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
    mov x29, #0  // Frame pointer
    mov x30, #0  // Link register

    // Stack temporário inicial antes do stack_init
    ldr sp, =0x80000000
    // Fim Parte 2

    // ===============================
    // Parte 3: Inicializa MMU e cache, chama stack_init
    // ===============================
    // Desabilita MMU temporariamente
    mrs x0, sctlr_el1
    bic x0, x0, #1
    msr sctlr_el1, x0

    // Configuração cache L1/L2 (simplificado)
    // Aqui você pode adicionar registros específicos do SOC

    // Configura tabela de páginas (TTBR0_EL1)
    ldr x1, =0x400000
    msr ttbr0_el1, x1

    // Habilita MMU
    mrs x0, sctlr_el1
    orr x0, x0, #1
    msr sctlr_el1, x0

    // Chama stack_init.S para stack final
    bl stack_init
    // Fim Parte 3

    // ===============================
    // Parte 4: Inicializa vetores de exceção e chama bootloader
    // ===============================
    bl exception_vectors
    bl auraOS_bootloader

    // Loop infinito se bootloader falhar
1:  b 1b

// ===============================
// Fim do cpu_init.S completo
// ===============================
