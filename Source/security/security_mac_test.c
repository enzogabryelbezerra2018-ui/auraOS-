// security/security_mac_test.c
// Teste de validação das regras MAC do AuraOS

#include <stdio.h>
#include "security_policy.h"

const char* domain_names[] = {
    "KERNEL",
    "SYSTEM_SERVICE",
    "SEVEN_UI",
    "AURA_APP",
    "THIRD_PARTY_APP"
};

const char* resource_names[] = {
    "NONE",
    "FILE_READ",
    "FILE_WRITE",
    "NET_SOCKET_TCP",
    "NET_SOCKET_UDP",
    "SYS_REBOOT",
    "HARDWARE_MMIO",
    "PROCESS_FORK",
    "INTER_PROCESS_COMM"
};

void test_mac_rules() {
    for (int d = 0; d < DOMAIN_MAX; ++d) {
        printf("=== Regras para domínio: %s ===\n", domain_names[d]);
        for (int r = 0; r < RES_MAX; ++r) {
            int allowed = security_check_mac((security_domain_t)d, (security_resource_t)r);
            printf("Recurso %s: %s\n", resource_names[r], allowed ? "PERMITIDO" : "NEGADO");
        }
        printf("\n");
    }
}

int main() {
    printf("==== Teste de Regras MAC do AuraOS ====\n\n");
    test_mac_rules();
    return 0;
}
