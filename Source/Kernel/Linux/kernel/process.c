#include "process.h"

#define MAX_PROCESSES 16
static process_t process_table[MAX_PROCESSES];
static uint32_t process_count = 0;

void create_init_process() {
    // Processo inicial placeholder
    process_table[process_count++] = (process_t){1,0,0};
}

void schedule_processes() {
    for(uint32_t i=0;i<process_count;i++){
        if(process_table[i].state==0){
            process_table[i].state=1; // running
            if(process_table[i].entry) process_table[i].entry();
            process_table[i].state=0; // ready
        }
    }
}
