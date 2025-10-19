// Source/security/security_policy_data.c
// Implementação da tabela de regras MAC (Controle de Acesso Obrigatório)

#include "security_policy.h"

// Define a tabela de regras MAC para o AuraOS- v1.0.0
const mac_rule_t g_mac_rules[] = {
    // === REGRAS PARA DOMAIN_KERNEL (Totalmente Confiável) ===
    {DOMAIN_KERNEL,          RES_FILE_READ,          1}, // Kernel pode ler tudo
    {DOMAIN_KERNEL,          RES_FILE_WRITE,         1}, // Kernel pode escrever tudo
    {DOMAIN_KERNEL,          RES_SYS_REBOOT,         1}, // Kernel pode reiniciar
    {DOMAIN_KERNEL,          RES_HARDWARE_MMIO,      1}, // Kernel tem acesso direto a MMIO

    // === REGRAS PARA DOMAIN_SYSTEM_SERVICE (Serviços Essenciais) ===
    {DOMAIN_SYSTEM_SERVICE,  RES_FILE_READ,          1}, // Serviços podem ler configs
    {DOMAIN_SYSTEM_SERVICE,  RES_NET_SOCKET_TCP,     1}, // Serviços podem usar a rede
    {DOMAIN_SYSTEM_SERVICE,  RES_NET_SOCKET_UDP,     1},
    {DOMAIN_SYSTEM_SERVICE,  RES_SYS_REBOOT,         0}, // NEGA: Serviços NÃO podem reiniciar o sistema
    {DOMAIN_SYSTEM_SERVICE,  RES_PROCESS_FORK,       1}, // Serviços podem iniciar subprocessos

    // === REGRAS PARA DOMAIN_SEVEN_UI (Aplicações de Interface Principal) ===
    {DOMAIN_SEVEN_UI,        RES_FILE_READ,          1}, // UI pode ler arquivos de usuário e configs
    {DOMAIN_SEVEN_UI,        RES_FILE_WRITE,         0}, // NEGA: UI NÃO pode escrever em diretórios do sistema
    {DOMAIN_SEVEN_UI,        RES_NET_SOCKET_TCP,     0}, // NEGA: A UI em si não deve ter acesso direto à rede
    {DOMAIN_SEVEN_UI,        RES_PROCESS_FORK,       1}, 

    // === REGRAS PARA DOMAIN_THIRD_PARTY_APP (Sandboxed) ===
    {DOMAIN_THIRD_PARTY_APP, RES_FILE_READ,          0}, // NEGA: Acesso a arquivos de sistema
    {DOMAIN_THIRD_PARTY_APP, RES_FILE_WRITE,         0}, // NEGA: Escrita em qualquer lugar fora de sua sandbox
    {DOMAIN_THIRD_PARTY_APP, RES_NET_SOCKET_TCP,     1}, // PERMITE: Acesso à rede (com monitoramento)
    {DOMAIN_THIRD_PARTY_APP, RES_HARDWARE_MMIO,      0}, // NEGA: Totalmente proibido

    // Adicione todas as outras regras...

};

// Contagem total de regras na tabela (para iteração rápida no motor de checagem)
const uint32_t G_MAC_RULE_COUNT = sizeof(g_mac_rules) / sizeof(mac_rule_t);


// Implementação da função de checagem (core do motor MAC)
int security_check_mac(security_domain_t domain, security_resource_t resource) {
    if (domain == DOMAIN_KERNEL) {
        return 1; // O kernel sempre tem permissão total
    }

    // Itera sobre a tabela de regras para encontrar uma correspondência
    for (uint32_t i = 0; i < G_MAC_RULE_COUNT; ++i) {
        if (g_mac_rules[i].domain == domain && g_mac_rules[i].resource == resource) {
            // Retorna o resultado da regra encontrada
            return g_mac_rules[i].allowed;
        }
    }
    
    // Política de negação por omissão: se nenhuma regra explícita for encontrada, nega-se o acesso.
    return 0;
}
