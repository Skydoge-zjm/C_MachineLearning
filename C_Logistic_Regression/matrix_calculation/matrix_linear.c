# include <stdio.h>
# include <stdlib.h>

# include "matrix_linear.h"

double * add_scalar(double * A, int m, int n, double x) {
    double * out = (double *) malloc(m * n * sizeof(double));
    if (out == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            out[i * n + j] = A[i * n + j] + x;
        }
    }
    return out;
}

double * add_matrix(double * A, double * B, int m1, int n1, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {
        printf("Error: Wrong matrix shape when add.");
        exit(2);
    }
    int m = m1;
    int n = n1;
    double * out = (double *) malloc(m * n * sizeof(double));
    if (out == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            out[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }
    return out;
}

double * scalar_mul(double * A, int m, int n, double x) {
    double * out = (double *) malloc(m * n * sizeof(double));
    if (out == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            out[i * n + j] = A[i * n + j] * x;
        }
    }
    return out;
}

double * linear_matrix(double * A, double * B, int m1, int n1, int m2, int n2, double x1, double x2) {
    if (m1 != m2 || n1 != n2) {
        printf("Error: Wrong matrix shape when add.");
        exit(2);
    }
    int m = m1;
    int n = n1;
    double * out = (double *) malloc(m * n * sizeof(double));
    if (out == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            out[i * n + j] = x1 * A[i * n + j] + x2 * B[i * n + j];
        }
    }
    return out;
}
