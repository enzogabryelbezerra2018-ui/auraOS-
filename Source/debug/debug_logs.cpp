#include <stdio.h>
#include <stdlib.h>

void show_logs() {
    printf("\n=== SYSTEM LOGS ===\n");
    printf("Boot: OK\n");
    printf("Kernel: OK\n");
    printf("CPU: OK\n");
    printf("RAM: OK\n");
    printf("Storage: OK\n");
    printf("Drivers: OK\n");
    printf("==================\n\n");
}

void test_hardware() {
    printf("\n=== HARDWARE TEST ===\n");
    printf("CPU test: OK\n");
    printf("RAM test: OK\n");
    printf("Storage test: OK\n");
    printf("Display test: OK\n");
    printf("Battery test: OK\n");
    printf("===================\n\n");
}

void show_status() {
    printf("\n=== DEVICE STATUS ===\n");
    printf("Device: AuraOS Test Device\n");
    printf("Firmware version: 0.1.0\n");
    printf("Battery: 95%%\n");
    printf("Temperature: 36 C\n");
    printf("Uptime: 0h 15m\n");
    printf("=====================\n\n");
}

void restart_device() {
    printf("\nReiniciando dispositivo...\n");
    exit(0); // simula reinício
}
