#include <stdio.h>
#include <stdbool.h>

int main() {
    long long n, i;
    printf("Enter a number: ");
    scanf("%lli", &n);

    bool is_prime = true;
    for (i = 2; i <= n >> 1; ++i) {
        if (n % i == 0) {
            is_prime = false; 
            break;
        }
    }

    if (is_prime) puts("The number is prime.");
    else puts("The number is composite.");

    return 0;
}
