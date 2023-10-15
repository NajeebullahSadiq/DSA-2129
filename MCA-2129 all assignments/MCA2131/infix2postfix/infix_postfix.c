#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(stack, c);
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            pop(stack); // Pop '(' from the stack
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack)))
                postfix[j++] = pop(stack);
            push(stack, c);
        }
    }

    while (!isEmpty(stack))
        postfix[j++] = pop(stack);

    postfix[j] = '\0';
    destroyStack(stack);
}

int evaluatePostfix(char* postfix) {
    Stack* stack = createStack(strlen(postfix));
    int i;

    for (i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isalnum(c))
            push(stack, c - '0'); // Convert character to integer
        else if (isOperator(c)) {
            int op2 = pop(stack);
            int op1 = pop(stack);
            switch (c) {
                case '+':
                    push(stack, op1 + op2);
                    break;
                case '-':
                    push(stack, op1 - op2);
                    break;
                case '*':
                    push(stack, op1 * op2);
                    break;
                case '/':
                    push(stack, op1 / op2);
                    break;
            }
        }
    }

    int result = pop(stack);
    destroyStack(stack);
    return result;
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
