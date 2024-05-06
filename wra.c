#include <stdio.h>
#include <string.h>
#define FILENAME "some.txt"

int main() {
    const char text[] = 
        "All lovely tales that we have heard or read:\n"
        "An endless fountain of immortal drink,\n";
    FILE *f = fopen(FILENAME, "w");
    fwrite(text, sizeof(char), strlen(text), f);
    fclose(f);

    size_t n = strchr(text, '\n') - text;
    char book[n];
    f = fopen(FILENAME, "r");
    fread(book, sizeof(char), n, f);
    printf("%s\n", book);
    fclose(f);

    const char text_more[] =
        "Pouring unto us from the heaven’s brink.";
    f = fopen(FILENAME, "a");
    fwrite(text_more, sizeof(char), strlen(text_more), f);
    fclose(f);

    return 0;
}
