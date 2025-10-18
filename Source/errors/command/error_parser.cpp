#include "error_parser.h"
#include <algorithm>

std::string parse_command(const std::string &input) {
    std::string cmd = input;
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    return cmd;
}
