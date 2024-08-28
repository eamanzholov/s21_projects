#include "stack.h"

#include <stdlib.h>

struct Stack* init() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack != NULL) {
        stack->top = NULL;
    }
    return stack;
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return 0;
    }

    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void destroy(struct Stack* stack) {
    while (stack->top != NULL) {
        struct StackNode* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
    free(stack);
}
