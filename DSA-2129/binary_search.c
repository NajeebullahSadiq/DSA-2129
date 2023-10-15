#include "binary_search.h"
#include <stdio.h>
#include <string.h>

#define WORDS_FILE "sorted_words.txt"

int binary_search(const char *target) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    FILE *file = fopen(WORDS_FILE, "r");

    if (file == NULL) {
        printf("Error: Could not open the file.\n");
        return -1;
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (fgets(words[i], MAX_WORD_LENGTH, file) == NULL) {
            break;
        }
        // Remove newline character and any hidden characters
        char *newline = strchr(words[i], '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
    }

    fclose(file);

    int left = 0;
    int right = MAX_WORDS - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int cmp = strcmp(words[middle], target);

        if (cmp == 0) {
            return middle;
        } else if (cmp < 0) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1; // Word not found
}
