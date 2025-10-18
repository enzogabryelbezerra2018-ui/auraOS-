#include "bsd_kernel.h"
#include <stdio.h>

void schedule_processes(std::vector<Process> &process_list){
    for(auto &p : process_list){
        if(p.running){
            printf("[Scheduler] Running process %d: %s\n", p.pid, p.name.c_str());
        }
    }
}
