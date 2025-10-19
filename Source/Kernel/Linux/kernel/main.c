#include "kernel.h"
#include "process.h"
#include "vfs.h"
#include "../drivers/drivers.h"
#include "security.h"

void kernel_main() {
    // Inicializa drivers essenciais
    vga_init();
    keyboard_init();
    timer_init();

    // Inicializa sistema de arquivos
    vfs_init();

    // Inicializa segurança MAC
    security_init();

    // Cria processo inicial (shell ou GUI)
    create_init_process();

    // Loop principal do kernel
    while(1) {
        schedule_processes();
    }
}
