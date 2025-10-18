#include "log_ui.h"
#include <iostream>

std::string log_level_to_string(LogLevel level){
    switch(level){
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void render_logs(const LogUI &log_ui){
    for(const auto &entry : log_ui.logs){
        std::cout << "[" << log_level_to_string(entry.level) << "] ";
        std::cout << entry.message;
        if(!entry.variables.empty()){
            std::cout << " (";
            for(int i=0;i<entry.variables.size();i++){
                std::cout << entry.variables[i];
                if(i < entry.variables.size()-1) std::cout << ", ";
            }
            std::cout << ")";
        }
        std::cout << std::endl;
    }
}
