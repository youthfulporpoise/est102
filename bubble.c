/*
 * BUBBLE SORT
 * A program to sort an array of integers using
 * the bubble sort alogrithm.
 */

#include <stdio.h>
#include <stdbool.h>

void bubble_sort (int*, size_t);
void swap (int*, int*);

int main() {
    size_t n, i;
    printf("Array length: ");
    scanf("%zu", &n);

    int array[n];
    for (i = 0; i < n; i++) {
        printf("Element %zu: ", i + 1);
        scanf("%d", array + i);
    }

    bubble_sort(array, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; ++i) printf("%d ", array[i]);
    puts("");

    return 0;
}

void bubble_sort(int* array, size_t n) {
    size_t i, j;
    bool was_swapped;
    for (i = 0; i < n; ++i) {
        was_swapped = false;
        for (j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
                was_swapped = true;
            }
        } 
        if (was_swapped) continue;
        else break;
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
