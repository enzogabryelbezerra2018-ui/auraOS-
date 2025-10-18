#ifndef ERROR_COMMAND_H
#define ERROR_COMMAND_H

#include "../error_handler.h"

class ErrorCommand {
public:
    ErrorCommand(ErrorHandler &handler);
    void execute(const std::string &input);

private:
    ErrorHandler &error_handler;
};

#endif
