#include <stdio.h>

void log_test_result(const char* test_name, bool passed){
    if(passed){
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
    }
}
