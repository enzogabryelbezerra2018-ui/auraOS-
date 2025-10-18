#include "alert_network.h"
#include <cstdlib>
#include <ctime>

Alert AlertNetwork::get_remote_alert() {
    Alert a;
    std::srand(std::time(nullptr));

    int type = std::rand() % 4;
    a.type = static_cast<AlertType>(type);

    switch(a.type) {
        case AlertType::GOVERNMENT:
            a.title = "Alerta Nacional de Emergência";
            a.message = "Evacue áreas de risco imediatamente.";
            break;
        case AlertType::WEATHER:
            a.title = "Tempestade Severa";
            a.message = "Chuvas intensas nas próximas horas.";
            break;
        case AlertType::SAFETY:
            a.title = "Alerta de Segurança Pública";
            a.message = "Evite deslocamentos. Área sob monitoramento.";
            break;
        case AlertType::SYSTEM:
            a.title = "Atualização Crítica do Sistema";
            a.message = "AuraOS precisa reiniciar para aplicar correções.";
            break;
        default:
            a.title = "Aviso Desconhecido";
            a.message = "Origem do alerta não identificada.";
            break;
    }

    a.timestamp = std::time(nullptr);
    return a;
}
