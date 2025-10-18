#ifndef ALERT_UI_H
#define ALERT_UI_H

#include "alert_system.h"

class AlertUI {
public:
    void render_alert(const Alert &alert);
    void render_alert_popup(const Alert &alert);
    void render_alert_animation();
};

#endif
