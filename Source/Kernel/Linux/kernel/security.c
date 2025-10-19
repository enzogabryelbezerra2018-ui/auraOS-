#include "security.h"
#include "../../security/security_policy.h"

void security_init() {
    // Inicializa regras MAC do AuraOS
}

int security_check(uint32_t pid, uint32_t resource) {
    return 1; // permite todos por enquanto
}
