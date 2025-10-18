#ifndef REBOOT_MANAGER_H
#define REBOOT_MANAGER_H

#include <string>

enum class RebootReason {
    USER_REQUEST,
    KERNEL_PANIC,
    DEBUG_RESET,
    UPDATE_COMPLETE
};

namespace Reboot {
    void request(RebootReason reason);
    void perform();
    std::string get_reason_string(RebootReason reason);
}

#endif
