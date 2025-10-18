#ifndef LOG_UI_H
#define LOG_UI_H

#include <string>
#include <vector>
#include <ctime>

enum class LogLevel {
    INFO,
    WARN,
    ERROR
};

struct LogEntry {
    LogLevel level;
    std::string message;
    std::time_t timestamp;
    std::vector<std::string> variables;
};

class LogUI {
public:
    std::vector<LogEntry> logs;

    void add_log(LogLevel level, const std::string &message, const std::vector<std::string> &vars = {});
    void clear_logs();
};

#endif
