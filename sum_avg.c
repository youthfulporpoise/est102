#include <stdio.h>

long sum (long*, size_t);
float avg (long*, size_t);

int main() {
    size_t n, i;
    printf("Data length: ");
    scanf("%zu", &n);

    long data[n];
    for (i = 0; i < n; ++i) {
        printf("Entry %zu: ", i + 1);
        scanf("%ld", data + i);
    }

    puts("");
    printf("Sum: %ld\n", sum(data, n));
    printf("Average %.3f\n", avg(data, n));
    return 0;
}

long sum(long* data, size_t n) {
    long acc = 0;
    size_t i;
    for (i = 0; i < n; ++i) acc = acc + data[i];
    return (acc);
}

float avg(long* data, size_t n) {
    float s = sum(data, n);
    return (s / n);
}
