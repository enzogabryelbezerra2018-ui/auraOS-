// boot_entry.S - Ponto de entrada ARM64 do AuraOS

.global _start
_start:
    bl cpu_init         // Inicializa CPU completa
    bl exception_vectors
    bl auraOS_bootloader

1: b 1b               // Loop infinito se algo falhar
