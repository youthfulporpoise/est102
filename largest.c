#include <stdio.h>

int main () {
    int a, b, c, z;
    printf("Enter 3 numbers (a b c): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b) z = a;
    else z = b;
    if (c >= z) z = c;
    
    printf("%d is the largest number.\n", z);

    return 0;
}
