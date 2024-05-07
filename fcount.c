#include <stdio.h>
#define FILENAME "some.txt"

int main() {
    size_t characters = 0, words = 1, lines = 1;
    FILE *f = fopen(FILENAME, "r");
    char c;
    while ((c = fgetc(f)) != EOF) {
        switch (c) {
            case (' '):
                words++;
                break;
            case ('\n'):
                words++;
                lines++;
                break;
            default:
                characters++;
        }
    } fclose(f);

    f = fopen(FILENAME, "a");
    fprintf(f, "\n"
            "Characters : %zu\n"
            "Words      : %zu\n"
            "Lines      : %zu\n",
            characters,
            characters > 0 ? words : 0,
            characters > 0 ? lines : 0);
    return 0;
}
