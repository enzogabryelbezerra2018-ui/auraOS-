#ifndef BSD_KERNEL_H
#define BSD_KERNEL_H

#include <stdint.h>
#include <vector>
#include <string>

struct Process {
    int pid;
    std::string name;
    bool running;
};

class BSDKernel {
public:
    std::vector<Process> process_list;

    BSDKernel();
    void init();
    void run();
    void create_process(const std::string &name);
};

#endif
