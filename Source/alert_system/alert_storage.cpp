#include "alert_storage.h"
#include <iostream>

void AlertStorage::save_alert(const Alert &alert) {
    storage.push_back(alert);
    std::cout << "[STORAGE] Alerta salvo localmente: " << alert.title << std::endl;
}

std::vector<Alert> AlertStorage::load_alerts() {
    return storage;
}
