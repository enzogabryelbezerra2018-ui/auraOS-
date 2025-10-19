// Source/security/security_policy.h
// Declarações do motor de checagem de políticas MAC.

#ifndef SECURITY_POLICY_H
#define SECURITY_POLICY_H

#include "security_types.h"

// Declaração da tabela de regras de política e sua contagem
extern const mac_rule_t g_mac_rules[];
extern const uint32_t G_MAC_RULE_COUNT;


/**
 * @brief Verifica se um domínio tem permissão para acessar um recurso.
 * * Esta é a função crítica de segurança do kernel. Ela é chamada por qualquer
 * subsistema (VFS, Rede, Gerenciamento de Processos) antes de conceder acesso.
 * * @param domain O contexto/processo que solicita o acesso.
 * @param resource O recurso ou operação solicitado.
 * @return 1 (true) se a operação for permitida; 0 (false) se negada.
 */
int security_check_mac(security_domain_t domain, security_resource_t resource);


#endif // SECURITY_POLICY_H
