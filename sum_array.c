/*
 *  THE SUM OF THE ELEMENTS OF AN ARRAY
 *
 *  Compute the sum of elements stored in an array using
 *  pointers and user-defined function.
 */

#include <stdio.h>

#define n_fmt "%lli"
typedef long long number;
number sum (number*, size_t);

int main() {
    size_t n;
    printf("Size: ");
    scanf("%zu", &n);

    number array[n];
    printf("Enter %zu elements: ", n);
    for (size_t i = 0; i < n; ++i) scanf(n_fmt, array + i);

    printf("Sum: " n_fmt "\n", sum(array, n));
    return 0;
}

number sum(number* array, size_t n) {
   number acc = 0;
   for (size_t i = 0; i < n; ++i) acc = acc + array[i];
   return acc;
}
