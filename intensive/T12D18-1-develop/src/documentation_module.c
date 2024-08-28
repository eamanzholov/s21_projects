#include "documentation_module.h"

#include <stdarg.h>
int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list factor;
    short mask = 0;
    va_start(factor, document_count);
    for (int i = 0; i < document_count; i++) {
        mask |= validate(va_arg(factor, char*));
        mask = mask << 1;
    }
    va_end(factor);
    mask = mask >> 1;
    return mask;
}