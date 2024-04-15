#include <stdio.h>
#include <stdbool.h>

bool is_vowel (char);
bool is_space (char);
bool is_consonant (char);

int main() {
    char string[64];
    unsigned int i;

    /* A string is read character-by-character until a dollar
       sign occurs or the length exceeds the array size. */
    printf("String: ");
    for (i = 0; i < 64; ++i) {
        if ((string[i] = fgetc(stdin)) == '$') {
            string[i] = '\0';
            break;
        } else continue;
    }

    unsigned int vowels = 0, consonants = 0, spaces = 0;
    for (i = 0; string[i] != '\0'; ++i) {
        char c = string[i];
        if (is_space(c)) spaces++;
        else if (is_vowel(c)) vowels++;
        else if (is_consonant(c)) consonants++;
        else continue;
    }

    printf("%u vowels\n"
           "%u consonants\n"
           "%u spaces\n", vowels, consonants, spaces);

    return 0;
}

bool is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else return false;
}

bool is_space(char c) {
    if (c == ' ') return true;
    else return false;
}

bool is_consonant(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return true;
    } else return false;
}
