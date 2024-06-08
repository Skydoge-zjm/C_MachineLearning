
#ifndef C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H
#define C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H

#define MAX_SIZE 1024

typedef struct {
    double* A;
    double* B;
    double* C;
    int m;
    int n;
    int p;
    int row;
    int col;
} MatrixParams;

void* matrix_multiply(void* args);
double * matmul_parallel(double * A, double * B, int m, int n, int p);
double * matmul(double * A, double * B, int m, int n1, int n2, int p);

#endif //C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H
