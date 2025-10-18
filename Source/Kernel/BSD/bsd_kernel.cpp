#include "bsd_kernel.h"
#include "process.cpp"
#include "memory.cpp"
#include "scheduler.cpp"
#include "interrupts.cpp"
#include <stdio.h>

BSDKernel::BSDKernel(){}

void BSDKernel::init(){
    printf("[BSDKernel] Initializing kernel...\n");
    // Inicializa memória, processos, dispositivos
    init_memory();
    init_interrupts();
}

void BSDKernel::run(){
    printf("[BSDKernel] Kernel running...\n");
    while(true){
        schedule_processes(process_list);
        // Loop infinito de kernel simulado
    }
}

void BSDKernel::create_process(const std::string &name){
    Process p;
    p.pid = process_list.size() + 1;
    p.name = name;
    p.running = true;
    process_list.push_back(p);
    printf("[BSDKernel] Process created: %s (PID %d)\n", name.c_str(), p.pid);
}
