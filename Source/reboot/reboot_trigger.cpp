#include "reboot_manager.h"
#include <iostream>

void handle_reboot_trigger(const std::string &source) {
    if (source == "debug") {
        Reboot::request(RebootReason::DEBUG_RESET);
    } else if (source == "panic") {
        Reboot::request(RebootReason::KERNEL_PANIC);
    } else if (source == "update") {
        Reboot::request(RebootReason::UPDATE_COMPLETE);
    } else {
        Reboot::request(RebootReason::USER_REQUEST);
    }
}
