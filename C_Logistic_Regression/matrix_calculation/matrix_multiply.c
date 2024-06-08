#include <stdio.h>
#include <stdlib.h>
# include <pthread.h>

# include "matrix_multiply.h"

void * matrix_multiply(void * args) {
    MatrixParams * params = (MatrixParams *) args;
    double sum = 0.0;
    for (int k = 0; k < params -> n; k++){
        int index1 = params -> row * params -> n + k;
        int index2 = k * params -> p + params -> col;
        sum += params -> A[index1] * params -> B[index2];
    }
    int index3 = params -> row * params -> p + params -> col;
    params -> C[index3] = sum;
    pthread_exit(NULL);
}

double * matmul_parallel(double * A, double * B, int m, int n, int p) {
    double * C = (double *) malloc(m * p * sizeof(double ) );
    if (C == NULL) {
        printf("Error: Fail to alloc memory.");
        return NULL;
    }

    pthread_t threads[m * p];
    MatrixParams params[m * p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            params[i * p + j].A = A;
            params[i * p + j].B = B;
            params[i * p + j].C = C;
            params[i * p + j].m = m;
            params[i * p + j].n = n;
            params[i * p + j].p = p;
            params[i * p + j].row = i;
            params[i * p + j].col = j;
            pthread_create(&threads[i * p + j], NULL,
                           matrix_multiply, &params[i * p + j]);

        }
    }

    for (int i = 0; i < m * p; i++) {
        pthread_join(threads[i], NULL);
    }

    return C;
}

double * matmul(double * A, double * B, int m, int n1, int n2, int p) {
    int n;
    if (m > MAX_SIZE || n1 > MAX_SIZE || n2 > MAX_SIZE || p > MAX_SIZE){
        printf("Error: Too large matrix_calculation.");
        return NULL;
    } else if (n1 != n2) {
        printf("Error: Wrong matrix_calculation shape.");
        return NULL;
    } else {
        n = n1;
    }
    double * C = matmul_parallel(A, B, m, n, p);
    return C;
}