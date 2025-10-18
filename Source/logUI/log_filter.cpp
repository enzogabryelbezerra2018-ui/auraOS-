#include "log_ui.h"
#include <vector>

std::vector<LogEntry> filter_logs_by_level(const LogUI &log_ui, LogLevel level){
    std::vector<LogEntry> result;
    for(const auto &entry : log_ui.logs){
        if(entry.level == level){
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<LogEntry> filter_logs_by_keyword(const LogUI &log_ui, const std::string &keyword){
    std::vector<LogEntry> result;
    for(const auto &entry : log_ui.logs){
        if(entry.message.find(keyword) != std::string::npos){
            result.push_back(entry);
        }
    }
    return result;
}
