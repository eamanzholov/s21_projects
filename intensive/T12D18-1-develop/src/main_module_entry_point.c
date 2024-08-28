#include <stdio.h>
#ifdef print_module
#include "print_module.h"
#elif documentation_module
#include "documentation_module.h"
#endif

int main() {
#ifdef print_module
    print_log(print_char, Module_load_success_message);
#elif documentation_module
    short availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    char qwe[Documents_count][100] = {Documents};
    for (int i = Documents_count - 1; i >= 0; i--) {
        if (availability_mask & 1) {
            printf("%-15s: available\n", qwe[i]);
        } else {
            printf("%-15s: unavailable\n", qwe[i]);
        }
        availability_mask = availability_mask >> 1;
    }
#endif
    return 0;
}