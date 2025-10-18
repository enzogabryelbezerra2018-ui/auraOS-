#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Variáveis de lógica
#define SOURCE_DIR "Source"
char* files[100];   // Lista de arquivos encontrados
int file_count = 0; // Quantidade de arquivos

// Função que lê todos os arquivos dentro da pasta Source
void list_source_files(const char* path) {
    struct dirent* entry;
    DIR* dp = opendir(path);
    if (dp == NULL) {
        printf("Erro ao abrir a pasta %s\n", path);
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            files[file_count] = strdup(entry->d_name);
            file_count++;
        }
    }
    closedir(dp);
}

int main() {
    printf("Listando arquivos do AuraOS na pasta %s:\n", SOURCE_DIR);
    
    list_source_files(SOURCE_DIR);

    // Exibe os arquivos encontrados
    for (int i = 0; i < file_count; i++) {
        printf("[%d] %s\n", i+1, files[i]);
    }

    printf("\nTotal de arquivos encontrados: %d\n", file_count);

    // Loop de lógica (simula execução de cada arquivo)
    for (int i = 0; i < file_count; i++) {
        printf("Executando módulo: %s ...\n", files[i]);
        usleep(300000); // Delay simulado de execução
    }

    printf("Todos os arquivos da pasta Source foram processados.\n");
    return 0;
}
