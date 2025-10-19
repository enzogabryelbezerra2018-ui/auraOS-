.global _start
_start:
    cli                 ; desabilita interrupções
    call kernel_main    ; chama kernel principal
hang:
    jmp hang
