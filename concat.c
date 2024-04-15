/*
 * We read two strings ending with a dollar sign ("$") and
 * concatenate them without library functions.
 */

#include <stdio.h>
#include <string.h>

int main() {
    size_t l = 64, i, j;
    char s1[l], s2[l], s[2 * l];

    printf("String 1 (ending with $): ");
    scanf("%s", s1);
    printf("String 2 (also ending with $): ");
    scanf("%s", s2);

    for (i = 0; s1[i] != '$' && s1[i] != '\0'; ++i) s[i] = s1[i];
    for (j = 0; s2[j] != '$' && s2[j] != '\0'; ++j) s[i + j] = s2[j];
    s[i + j] = '\0';

    printf("String: %s\n", s);

    return 0;
}
