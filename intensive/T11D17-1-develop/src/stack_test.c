#include "stack.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_push_pop() {
    struct Stack* stack = init();

    push(stack, 42);
    push(stack, 17);
    push(stack, 99);

    if (pop(stack) != 99) {
        return FAIL;
    }

    if (pop(stack) != 17) {
        return FAIL;
    }

    if (pop(stack) != 42) {
        return FAIL;
    }

    destroy(stack);
    return SUCCESS;
}

int main() {
    if (test_push_pop() == SUCCESS) {
        printf("Test push/pop: SUCCESS\n");
        return SUCCESS;
    } else {
        printf("Test push/pop: FAIL\n");
        return FAIL;
    }
}
