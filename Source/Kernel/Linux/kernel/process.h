#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

typedef struct {
    uint32_t pid;
    uint32_t state; // 0=ready,1=running,2=blocked
    void (*entry)();
} process_t;

void create_init_process();
void schedule_processes();

#endif
