/*
 * Input and print the elements of an array
 * using pointers.
 */
#include <stdio.h>

int main() {
    size_t n;
    printf("Array size: ");
    scanf("%zu", &n);

    int array[n];
    printf("Array elements: ");
    for (size_t i = 0; i < n; ++i) scanf("%d", array + i);

    printf("Elements:");
    for (size_t i = 0; i < n; ++i) printf(" %d", *(array + i));
    puts("");

    return 0;
}
