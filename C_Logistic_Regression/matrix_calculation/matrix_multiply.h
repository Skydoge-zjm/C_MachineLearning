
#ifndef C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H
#define C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H

#define MAX_SIZE 4096

#define NUM_THREADS 64

struct v {
    int start;
    int end;
    int A_rows;
    int A_cols;
    int B_cols;
    double *A;
    double *B;
    double *C;
};

void *runner(void *param);
void multiply_thread(double *A, double *B, double *C, int A_rows, int A_cols, int B_cols);
double * matmul(double * A, double * B, int m, int n1, int n2, int p);

#endif //C_LOGISTIC_REGRESSION_MATRIX_MULTIPLY_H
