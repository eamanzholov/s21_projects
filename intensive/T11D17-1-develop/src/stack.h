#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct Stack* init();
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);
void destroy(struct Stack* stack);

#endif
