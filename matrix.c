/* 
 * Write a menu-driven program for performing matrix addition, multiplication,
 * and matrix transpose, using functions to (i) read a matrix, (ii) find the sum
 * of two matrices, (iii) find the product of two matrices, (iv) find the
 * transpose of a matrix, (v) display a matrix.
 *
 */
#include <stdio.h>
#include <math.h>
// #include <stdlib.h>

typedef struct Matrix {
    size_t m; /* row */
    size_t n; /* column */
    long long matrix[10][10];
    /* the number of digits of the largest matrix elment */
    unsigned max;
} Matrix;

void display_matrix(Matrix X) {
    printf("I verify: %zu %zu %u\n", X.m, X.n, X.max);
    puts("");
    for (size_t i = 0; i < X.m; ++i) {
        printf("\t");
        for (size_t j = 0; j < X.n; ++j) {
            printf("%*lld ", 2, X.matrix[i][j]);
        } puts("");
    } puts("");
}

void populate_matrix(Matrix X) {
    size_t m = X.m, n = X.n;
    for (size_t i = 0; i < m; ++i) {
        printf("\tRow %zu: ", i);
        for (size_t j = 0; j < n; ++j) {
            scanf("%lld", &X.matrix[i][j]);
            unsigned digitc = floor(log10(X.matrix[i][j])) + 1;
            X.max = digitc > X.max ? digitc : X.max;
            printf("X.max = %u\n", X.max);
        }
    }
}

void add_matrix(Matrix A, Matrix B, Matrix C) {
    /* It is assumed that A.m == B.m and A.n == B.n. */
    C.max = 0;
    for (size_t i = 0; i < C.m; ++i) {
        for (size_t j = 0; i < C.n; ++j) {
            C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            C.max = C.matrix[i][j] > C.max ? C.matrix[i][j] : C.max;
        }
    }
}

void mutiply_matrix(Matrix A, Matrix B, Matrix C) {
    for (size_t i = 0; i < A.m; ++i) {
        for (size_t j = 0; j < B.n; ++j) {
            for (size_t k = 0; k < A.n; ++k) {
                C.matrix[i][j] = A.matrix[i][k] * B.matrix[k][j];
            }
        }
    }
}

int main() {
    unsigned choice;
    printf("Choose an action:\n"
           "\t(1) add two matrices;\n"
           "\t(2) multiply two matrices;\n"
           "\t(3) transpose a matrix.\n"
           "Choice: ");
    scanf("%u", &choice);

    switch (choice) {
        case (1): {
            size_t m, n;
            printf("<row> <column>: ");
            scanf("%zu %zu", &m, &n);
            printf("I repeat: %zu %zu\n", m, n);
            static Matrix A = {.m = m, .n = n};
            Matrix B = {.m = m, .n = n};
            Matrix C = {.m = m, .n = n};
            puts("Matrix A"); populate_matrix(A);
            // puts("Matrix B"); populate_matrix(B);
            printf("A.max = %u\n", A.max);
            display_matrix(A);
            // add_matrix(A, B, C);
            break;
        } default:
            puts("Nothing.");
    }
    return 0;
}
