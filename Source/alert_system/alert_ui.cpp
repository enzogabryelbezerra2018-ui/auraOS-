#include "alert_ui.h"
#include <iostream>
#include <thread>
#include <chrono>

void set_color_rgb(int r, int g, int b) {
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void reset_color() {
    std::cout << "\033[0m";
}

void AlertUI::render_alert(const Alert &alert) {
    system("clear || cls");

    int r = 255, g = 0, b = 0;
    switch (alert.type) {
        case AlertType::GOVERNMENT: r = 255; g = 20; b = 20; break;
        case AlertType::WEATHER: r = 0; g = 150; b = 255; break;
        case AlertType::SAFETY: r = 255; g = 140; b = 0; break;
        case AlertType::SYSTEM: r = 0; g = 255; b = 120; break;
        default: r = 255; g = 255; b = 255; break;
    }

    set_color_rgb(r, g, b);
    std::cout << "╔══════════════════════════════════╗\n";
    std::cout << "║ 🚨  " << alert.title << "  🚨 ║\n";
    std::cout << "╚══════════════════════════════════╝\n";
    reset_color();

    std::cout << "\n📢 Mensagem: " << alert.message << "\n";
    std::cout << "📅 Recebido em: " << std::ctime(&alert.timestamp) << std::endl;
    std::cout << "\nPressione qualquer tecla para continuar...\n";
}

void AlertUI::render_alert_popup(const Alert &alert) {
    set_color_rgb(255, 255, 0);
    std::cout << "\n🔔 ALERTA URGENTE: " << alert.title << "\n";
    reset_color();
}

void AlertUI::render_alert_animation() {
    std::cout << "\n[ANIMAÇÃO DE ALERTA INICIADA]\n";
    for (int i = 0; i < 10; ++i) {
        set_color_rgb(255, 0, 0);
        std::cout << "█";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        set_color_rgb(255, 255, 0);
        std::cout << "█";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        set_color_rgb(0, 255, 0);
        std::cout << "█";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        set_color_rgb(0, 255, 255);
        std::cout << "█";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    reset_color();
    std::cout << "\n[ALERTA VISUAL COMPLETO]\n";
}
