/* 
 * Write a menu-driven program for performing matrix addition, multiplication,
 * and matrix transpose, using functions to (i) read a matrix, (ii) find the sum
 * of two matrices, (iii) find the product of two matrices, (iv) find the
 * transpose of a matrix, (v) display a matrix.
 */
#include <stdio.h>
#include <math.h>
// #include <stdlib.h>

typedef struct Matrix {
    size_t m; /* row */
    size_t n; /* column */
    long long matrix[10][10];
} Matrix;

void display_matrix(Matrix X) {
    unsigned size = 0;
    for (size_t i = 0; i < X.m; ++i) {
        for (size_t j = 0; j < X.n; ++j) {
            unsigned digitc = floor(log10(X.matrix[i][j])) + 1;
            size = digitc > size ? digitc : size;
        }
    }
    for (size_t i = 0; i < X.m; ++i) {
        printf("\t[ ");
        for (size_t j = 0; j < X.n; ++j) {
            printf("%*lld ", size, X.matrix[i][j]);
        } puts(" ]");
    }
}

void populate_matrix(Matrix *X) {
    size_t m = X->m, n = X->n;
    for (size_t i = 0; i < m; ++i) {
        printf("\tRow %zu: ", i + 1);
        for (size_t j = 0; j < n; ++j) {
            scanf("%lld", &X->matrix[i][j]);
        }
    }
}

void add_matrix(Matrix A, Matrix B, Matrix *C) {
    /* It is assumed that A.m == B.m and A.n == B.n. */
    for (size_t i = 0; i < C->m; ++i) {
        for (size_t j = 0; j < C->n; ++j) {
            C->matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
}

void multiply_matrix(Matrix A, Matrix B, Matrix *C) {
    for (size_t i = 0; i < A.m; ++i) {
        for (size_t j = 0; j < B.n; ++j) {
            long long s = 0;
            for (size_t k = 0; k < A.n; ++k) {
                s = s + A.matrix[i][k] * B.matrix[k][j];
            } C->matrix[i][j] = s;
        }
    }
}

void transpose_matrix(Matrix X, Matrix *C) {
    for (size_t i = 0; i < X.m; ++i) {
        for (size_t j = 0; j < X.n; ++j) {
            C->matrix[j][i] = X.matrix[i][j];
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
            Matrix A = {.m = m, .n = n};
            Matrix B = {.m = m, .n = n};
            Matrix C = {.m = m, .n = n};
            puts("Matrix A"); populate_matrix(&A);
            puts("Matrix B"); populate_matrix(&B);
            add_matrix(A, B, &C);
            puts("Sum: "); display_matrix(C);
            break;
        } case (2): {
            size_t m, n;
            printf("<row> <column>: ");
            scanf("%zu %zu", &m, &n);
            Matrix A = {.m = m, .n = n};
            Matrix B = {.m = m, .n = n};
            Matrix C = {.m = m, .n = n};
            puts("Matrix A"); populate_matrix(&A);
            puts("Matrix B"); populate_matrix(&B);
            multiply_matrix(A, B, &C);
            puts("Product: "); display_matrix(C);
        } case (3): {
            size_t m, n;
            printf("<row> <column>: ");
            scanf("%zu %zu", &m, &n);
            Matrix X = {.m = m, .n = n};
            Matrix C = {.m = n, .n = m};
            puts("Matrix X"); populate_matrix(&X);
            transpose_matrix(X, &C);
            puts("Tranpose: "); display_matrix(C);
        } default: {
            puts("Exiting.");
            return 0;
        }
    }
    return 0;
}
