// exception_vector.S - Vetores de exceção ARM64

.global exception_vectors
exception_vectors:
    b reset_handler
    b undef_handler
    b svc_handler
    b prefetch_abort_handler
    b data_abort_handler
    b irq_handler
    b fiq_handler

reset_handler: b .
undef_handler: b .
svc_handler: b .
prefetch_abort_handler: b .
data_abort_handler: b .
irq_handler: b .
fiq_handler: b .
