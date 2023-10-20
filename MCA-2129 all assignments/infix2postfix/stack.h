#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, char item);
char pop(Stack* stack);
char peek(Stack* stack);
void destroyStack(Stack* stack);

#endif
