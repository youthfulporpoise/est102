/*
 * An Armstrong number is the sum of its digits raised to
 * the power of its number of digits.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_armstrong(unsigned int);

int main () {
    unsigned int n;
    printf("Number: ");
    scanf("%u", &n);

    if (is_armstrong(n)) printf("%u is an Armstrong number.\n", n);
    else printf("%u is not an Armstrong number.\n", n);
    return 0;
}

bool is_armstrong(unsigned int n) {
    unsigned int digitc = floor(log10(n) + 1), i;
    unsigned int digits[digitc], s = 0, z;
    for (i = 0; i < digitc; ++i) {
        z = n / (unsigned int)(pow(10, i)) % 10;
        s = s + pow(z, digitc);
    }
    return (s == n ? true : false);
}
