#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

#include "alert_system.h"
#include <vector>

class AlertManager {
public:
    void receive_alert(const Alert &alert);
    void show_alerts() const;
    void clear_alerts();

private:
    std::vector<Alert> alerts;
};

#endif
