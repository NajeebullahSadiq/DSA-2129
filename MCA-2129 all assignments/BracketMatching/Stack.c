#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(sizeof(char) * capacity);
    return stack;
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool push(Stack *stack, char item) {
    if (isFull(stack)) {
        return false;
    }
    stack->data[++stack->top] = item;
    return true;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; // Indicates an empty stack
    }
    return stack->data[stack->top--];
}

char peek(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; // Indicates an empty stack
    }
    return stack->data[stack->top];
}
