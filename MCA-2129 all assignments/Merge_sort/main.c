#include <stdio.h>
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include "merge_sort.h"

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory dynamically

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    int j;
    for (j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    free(arr); // Free the dynamically allocated memory

    return 0;
}
