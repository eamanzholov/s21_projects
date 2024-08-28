#include "logger.h"

#include <stdio.h>
#include <stdlib.h>

FILE* log_init(char* filename) {
    FILE* file = fopen(filename, "a+");
    return file;
}