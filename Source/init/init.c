#include "init.h"
#include "../log/log.h"
#include <stdio.h>

// Função que inicializa os módulos essenciais do AuraOS
void init_system() {
    // Mensagem inicial
    printf("[Init] Inicializando sistema...\n");

    // Inicialização de módulos principais
    log_message("Init: Sistema inicializado com sucesso.");

    // Aqui você pode inicializar hardware, periféricos ou módulos futuros
    printf("[Init] Módulos essenciais prontos.\n");
}
