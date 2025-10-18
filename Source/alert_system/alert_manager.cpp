#include "alert_manager.h"
#include "alert_sound.cpp"
#include <iostream>
#include <iomanip>
#include <ctime>

void AlertManager::receive_alert(const Alert &alert) {
    alerts.push_back(alert);
    play_alert_sound();

    std::cout << "\n🚨 [ALERTA RECEBIDO] 🚨\n";
    std::cout << "Tipo: ";
    switch(alert.type) {
        case AlertType::GOVERNMENT: std::cout << "Governo"; break;
        case AlertType::WEATHER: std::cout << "Clima"; break;
        case AlertType::SAFETY: std::cout << "Segurança"; break;
        case AlertType::SYSTEM: std::cout << "Sistema"; break;
        default: std::cout << "Desconhecido"; break;
    }
    std::cout << "\nTítulo: " << alert.title << "\nMensagem: " << alert.message << "\n";
}

void AlertManager::show_alerts() const {
    if(alerts.empty()) {
        std::cout << "Nenhum alerta recebido.\n";
        return;
    }

    std::cout << "\n=== HISTÓRICO DE ALERTAS ===\n";
    for (const auto &a : alerts) {
        std::tm* t = std::localtime(&a.timestamp);
        std::cout << "- [" << std::put_time(t, "%H:%M:%S") << "] " << a.title << " → " << a.message << "\n";
    }
    std::cout << "=============================\n";
}

void AlertManager::clear_alerts() {
    alerts.clear();
    std::cout << "✅ Histórico de alertas limpo.\n";
}
