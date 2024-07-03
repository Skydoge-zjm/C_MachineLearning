#include <stdio.h>
#include <stdlib.h>
# include <pthread.h>

# include "matrix_multiply.h"

void *runner(void *param) {
    struct v *data = param;
    int i, j, k;
    for (i = data->start; i < data->end; i++) {
        for (j = 0; j < data->B_cols; j++) {
            double dot = 0.0;
            for (k = 0; k < data->A_cols; k++) {
                dot += data->A[i * data->A_cols + k] * data->B[k * data->B_cols + j];
            }
            data->C[i * data->B_cols + j] = dot;
        }
    }
    free(data);
    pthread_exit(0);
}

void multiply_thread(double *A, double *B, double *C, int A_rows, int A_cols, int B_cols) {
    int i;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    for (i = 0; i < NUM_THREADS; i++) {
        struct v *data = (struct v*)malloc(sizeof(struct v));
        data->start = i * ((A_rows + NUM_THREADS - 1) / NUM_THREADS);
        data->end = (i + 1) * ((A_rows + NUM_THREADS - 1) / NUM_THREADS);
        data->A_rows = A_rows;
        data->A_cols = A_cols;
        data->B_cols = B_cols;
        data->A = A;
        data->B = B;
        data->C = C;
        if (data->end > A_rows) {
            data->end = A_rows;
        }
        pthread_attr_init(&attr);
        pthread_create(&tid[i], &attr, runner, data);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
}

double* matmul(double *A, double *B, int A_rows, int A_cols, int B_rows, int B_cols) {
    if (A_cols != B_rows) {
        printf("Matrix dimensions do not match for multiplication.\n");
        return NULL;
    }

    double *C = (double*)malloc(sizeof(double) * A_rows * B_cols);

    multiply_thread(A, B, C, A_rows, A_cols, B_cols);

    return C;
}