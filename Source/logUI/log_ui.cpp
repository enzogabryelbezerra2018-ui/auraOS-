#include "log_ui.h"
#include <iostream>
#include <ctime>

void LogUI::add_log(LogLevel level, const std::string &message, const std::vector<std::string> &vars){
    LogEntry entry;
    entry.level = level;
    entry.message = message;
    entry.timestamp = std::time(nullptr);
    entry.variables = vars;
    logs.push_back(entry);
}

void LogUI::clear_logs(){
    logs.clear();
}
