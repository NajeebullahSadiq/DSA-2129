#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

bool isBracketMatched(const char *expression) {
    Stack *stack = createStack(100); // Adjust the capacity as needed

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(stack, currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (isEmpty(stack)) {
                freeStack(stack);
                return false;
            }
            char topChar = pop(stack);
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == '}' && topChar != '{') ||
                (currentChar == ']' && topChar != '[')) {
                freeStack(stack);
                return false;
            }
        }
    }

    bool isBalanced = isEmpty(stack);
    freeStack(stack);
    return isBalanced;
}

int main() {
    char expression[100]; // Allow for a maximum expression length of 100 characters
    printf("Enter an expression with brackets: ");
    fgets(expression, sizeof(expression), stdin);

    if (isBracketMatched(expression)) {
        printf("Brackets are balanced.\n");
    } else {
        printf("Brackets are not balanced.\n");
    }
    return 0;
}
