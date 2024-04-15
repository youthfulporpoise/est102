#include <stdio.h>
#include <string.h>

void revstr (char*);

int main() {
    char string[64];
    printf("String: ");
    scanf("%s", string);

    revstr(string);
    printf("Reverse: %s\n", string);
    return 0;
}

void revstr(char* string) {

    char rstring[64];
    size_t l = strlen(string) - 1, i;
    for (i = 0; i <= l; ++i) rstring[i] = string[i];
    for (i = 0; i <= l; ++i) string[i] = rstring[l - i];

}
