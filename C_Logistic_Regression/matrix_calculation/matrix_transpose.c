#include <stdio.h>
#include <stdlib.h>

#include "matrix_transpose.h"

double* transpose(double* matrix, int m, int n) {
    double * transposed = (double *) malloc(m * n * sizeof (double));
    if (transposed == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j * m + i] = matrix[i * n + j];
        }
    }

    return transposed;
}