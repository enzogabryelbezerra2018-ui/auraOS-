#include "alert_system/alert_manager.h"
#include "alert_system/alert_network.h"
#include "alert_system/alert_storage.h"
#include "alert_system/alert_ui.h"

int main() {
    AlertManager manager;
    AlertNetwork network;
    AlertStorage storage;
    AlertUI ui;

    // Recebe um alerta simulado
    Alert alert = network.get_remote_alert();

    // Mostra UI com cores e animação RGB
    ui.render_alert_animation();
    ui.render_alert(alert);
    ui.render_alert_popup(alert);

    // Salva e exibe histórico
    storage.save_alert(alert);
    manager.receive_alert(alert);
    manager.show_alerts();

    return 0;
}
