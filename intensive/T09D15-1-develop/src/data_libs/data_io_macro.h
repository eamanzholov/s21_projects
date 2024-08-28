#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>

// Макрос для вывода массива любого типа
#define OUTPUT_ARRAY(array, size, format) \
    do { \
        for (int i = 0; i < size; ++i) { \
            printf(format, array[i]); \
        } \
        printf("\n"); \
    } while(0)

// Макрос для ввода массива любого типа
#define INPUT_ARRAY(array, size, format) \
    do { \
        for (int i = 0; i < size; ++i) { \
            if (scanf(format, &array[i]) != 1) { \
                printf("Invalid input.\n"); \
                exit(1); \
            } \
        } \
    } while(0)

#endif
