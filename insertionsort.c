#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, j, key;
    int *array;

    printf("Enter the no.of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements.\n");
        return 1;
    }

    array = malloc((size_t)n * sizeof *array);
    if (array == NULL) {
        fprintf(stderr, "Unable to allocate memory for the array.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid element.\n");
            free(array);
            return 1;
        }
    }

    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    printf("Sorted array: <");
    for (i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) printf(", ");
    }
    printf(">\n");

    free(array);
    return 0;
}
