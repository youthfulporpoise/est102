#include <stdio.h>

unsigned long long iter_fact (unsigned long long);
unsigned long long recr_fact (unsigned long long);

int main() {
    unsigned long long n;
    printf("Integer: ");
    scanf("%llu", &n);

    printf("Iterative factorial: %llu\n", iter_fact(n));
    printf("Recursive factorial: %llu\n", recr_fact(n));
    return 0;
}

unsigned long long iter_fact(unsigned long long n) {
    unsigned long long acc = 1, i;
    for (i = 1; i <= n; ++i) acc = acc * i;
    return (acc);
}

unsigned long long recr_fact(unsigned long long n) {
    if (n == 0 || n == 1) return 1;
    else return (n * recr_fact(n - 1));
}
