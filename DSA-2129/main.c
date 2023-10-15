#include <stdio.h>
#include "binary_search.h"

int main() {
    char target[MAX_WORD_LENGTH];
    
    printf("Enter a word to search: ");
    scanf("%s", target);

    int index = binary_search(target);

    if (index != -1) {
        printf("Word '%s' is found at line %d.\n", target, index + 1);
    } else {
        printf("Word '%s' is not found.\n", target);
    }

    return 0;
}
