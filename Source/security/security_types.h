// Source/security/security_types.h
// Tipos e definições de segurança para o Subsistema MAC (Mandatory Access Control).

#ifndef SECURITY_TYPES_H
#define SECURITY_TYPES_H

#include <stdint.h>

// ===================================
// Definição dos Recursos (O que o processo quer fazer?)
// ===================================
typedef enum {
    RES_NONE = 0,
    RES_FILE_READ,          // 1: Leitura de arquivos (exceto /tmp)
    RES_FILE_WRITE,         // 2: Escrita de arquivos (exceto /tmp)
    RES_NET_SOCKET_TCP,     // 3: Criação de socket de rede (conexão TCP)
    RES_NET_SOCKET_UDP,     // 4: Criação de socket de rede (conexão UDP)
    RES_SYS_REBOOT,         // 5: Chamada de sistema para reboot/shutdown
    RES_HARDWARE_MMIO,      // 6: Acesso direto à memória mapeada de I/O (drivers)
    RES_PROCESS_FORK,       // 7: Criação de novos processos
    RES_INTER_PROCESS_COMM, // 8: Comunicação entre processos
    
    // Adicione outros recursos críticos aqui...
    RES_MAX
} security_resource_t;

// ===================================
// Tipos de Domínio/Contexto (Quem está fazendo o pedido?)
// ===================================
typedef enum {
    DOMAIN_KERNEL = 0,         // Kernel core (maior privilégio)
    DOMAIN_SYSTEM_SERVICE,     // Servidores de sistema (e.g., Network Manager)
    DOMAIN_SEVEN_UI,           // Processo da interface gráfica (nível de usuário alto)
    DOMAIN_AURA_APP,           // Aplicativos nativos confiáveis do AuraOS
    DOMAIN_THIRD_PARTY_APP,    // Aplicativos de terceiros (mais restrito - sandboxed)
    
    DOMAIN_MAX
} security_domain_t;

// Estrutura para uma regra de política MAC
typedef struct {
    security_domain_t domain;
    security_resource_t resource;
    uint8_t allowed; // 1 = Permitido, 0 = Negado (padrão de negação)
} mac_rule_t;


#endif // SECURITY_TYPES_H
