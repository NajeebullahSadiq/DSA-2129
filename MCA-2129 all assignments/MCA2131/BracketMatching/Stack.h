#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define a struct for the stack
typedef struct Stack {
    char *data;
    int capacity;
    int top;
} Stack;

// Function prototypes
Stack* createStack(int capacity);
void freeStack(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
bool push(Stack *stack, char item);
char pop(Stack *stack);
char peek(Stack *stack);

#endif
