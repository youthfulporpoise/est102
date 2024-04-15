#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome (char*);

int main() {
    size_t l = 64;
    char word[l];
    printf("Word: ");
    // fgets(word, l, stdin);
    scanf("%s", word);

    if (is_palindrome(word)) printf("'%s' is a palindrome.\n", word);
    else printf("'%s' is not a palindrome.\n", word);

    return 0;
}

bool is_palindrome(char* word) {
    size_t n = strlen(word) - 1, i;
    char rword[n];

    for (i = 0; i <= n; ++i) rword[i] = word[n - i];
    return (strncmp(word, rword, n) == 0 ? true : false);
}
