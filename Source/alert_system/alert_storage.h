#ifndef ALERT_STORAGE_H
#define ALERT_STORAGE_H

#include "alert_system.h"
#include <vector>

class AlertStorage {
public:
    void save_alert(const Alert &alert);
    std::vector<Alert> load_alerts();

private:
    std::vector<Alert> storage;
};

#endif
