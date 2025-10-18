#ifndef ALERT_SYSTEM_H
#define ALERT_SYSTEM_H

#include <string>
#include <vector>
#include <ctime>

enum class AlertType {
    GOVERNMENT,
    WEATHER,
    SAFETY,
    SYSTEM,
    UNKNOWN
};

struct Alert {
    AlertType type;
    std::string title;
    std::string message;
    std::time_t timestamp;
};

#endif
