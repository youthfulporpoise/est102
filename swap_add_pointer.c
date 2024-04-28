/*
 * Add and swap two numbers using pointers
 * and user-defined functions.
 */
#include <stdio.h>

long add (long* a, long* b);
void swap (long* a, long* b);

int main() {
    long a, b;
    printf("Number 1: "); scanf("%ld", &a);
    printf("Number 2: "); scanf("%ld", &b);

    int choice;
    printf("Choose an action:\n"
           "\t(1) add the numbers\n"
           "\t(2) swap the numbers\n"
           "\nChoice: ");
    scanf("%d", &choice);

    puts("");
    switch (choice) {
        case (1):
            printf("Sum: %ld\n", add(&a, &b));
            break;
        case (2):
            swap(&a, &b);
            printf("Number 1: %ld\n"
                   "Number 2: %ld\n",
                   a, b);
            break;
        default:
            puts("Doing nothing.");
    }

    return 0;
}

long add(long* a, long* b) {
    return (*a + *b);
}

void swap(long* a, long* b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}
