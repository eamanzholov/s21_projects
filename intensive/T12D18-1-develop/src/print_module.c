#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    char _time[25];
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    strftime(_time, 40, "%H:%M:%S", u);
    for (int i = 0; Log_prefix[i] != 0; i++) {
        print(Log_prefix[i]);
    }
    print(' ');
    for (int i = 0; _time[i] != 0; i++) {
        print(_time[i]);
    }
    print(' ');
    for (int i = 0; message[i] != 0; i++) {
        print(message[i]);
    }
}