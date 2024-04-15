/*
 * A program to search an element in an array with 
 * the linear search algorithm
 */

#include <stdio.h>

size_t linear_search(int*, size_t, int);

int main() {
    /* Read the array size. */
    size_t n, i;
    printf("Number of elements: ");
    scanf("%zu", &n);

    /* Read the array elements. */
    int array[n];
    for (i = 0; i < n; ++i) {
        printf("Element %zu: ", i + 1);
        scanf("%d", array + i);
    }

    /* Read the key to find. */
    int k;
    printf("Element to search: ");
    scanf("%d", &k);

    /* Search for the key in the array. */
    size_t r = linear_search(array, n, k);
    if (r == n) puts("The key does not occur.");
    else printf("The key occurs first at %zu.\n", r);
    return 0;
}

size_t linear_search(int* array, size_t n, int k) {
    size_t i;
    for (i = 0; i < n; ++i)
        if (array[i] == k) break;
    return (i);
}
