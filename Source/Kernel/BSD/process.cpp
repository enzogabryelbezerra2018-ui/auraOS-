#include "bsd_kernel.h"
#include <stdio.h>

void list_processes(const std::vector<Process> &process_list){
    printf("[Processes] Listing %d processes:\n", (int)process_list.size());
    for(const auto &p : process_list){
        printf("PID %d: %s [%s]\n", p.pid, p.name.c_str(), p.running ? "running" : "stopped");
    }
}
