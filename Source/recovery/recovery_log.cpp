#include <iostream>
#include <vector>
#include <string>

static std::vector<std::string> recovery_logs;

void log_recovery(const std::string &msg) {
    recovery_logs.push_back(msg);
    std::cout << "[LOG] " << msg << std::endl;
}
