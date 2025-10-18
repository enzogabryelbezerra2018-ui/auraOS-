#ifndef ERROR_CODES_H
#define ERROR_CODES_H

enum class AuraError {
    NONE = 0,
    FILE_NOT_FOUND,
    PERMISSION_DENIED,
    MEMORY_LEAK,
    DEVICE_NOT_RESPONDING,
    KERNEL_PANIC,
    BOOT_FAILURE,
    UNKNOWN_ERROR
};

inline const char* get_error_message(AuraError code) {
    switch(code) {
        case AuraError::FILE_NOT_FOUND: return "Arquivo não encontrado";
        case AuraError::PERMISSION_DENIED: return "Permissão negada";
        case AuraError::MEMORY_LEAK: return "Vazamento de memória detectado";
        case AuraError::DEVICE_NOT_RESPONDING: return "Dispositivo não está respondendo";
        case AuraError::KERNEL_PANIC: return "Kernel Panic detectado!";
        case AuraError::BOOT_FAILURE: return "Falha de inicialização do sistema";
        default: return "Erro desconhecido";
    }
}

#endif
