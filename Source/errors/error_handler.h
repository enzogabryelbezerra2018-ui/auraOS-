#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "error_codes.h"
#include <string>
#include <vector>

struct ErrorEntry {
    AuraError code;
    std::string message;
    std::string module;
};

class ErrorHandler {
public:
    void raise_error(AuraError code, const std::string &module);
    void list_errors() const;
    void clear_errors();

private:
    std::vector<ErrorEntry> errors;
};

#endif
