#include <stdio.h>

int main() {
    long long unsigned n;
    printf("Enter limit: ");
    scanf("%llu", &n);

    printf("The sum is %llu.\n", n * (n + 1) / 2);
    
    return 0;
}
