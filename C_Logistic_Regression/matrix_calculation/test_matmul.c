#include <stdio.h>
#include <stdlib.h>
#include "matrix_multiply.h"

int main_test_matmul()
{
    double* A = (double *) malloc(300*400*sizeof(double));
    double* B = (double *) malloc(400*20*sizeof(double));
    double a = 0.0;
    for (int i=0; i<300*400; i++){
        A[i] = a;
        a += 0.001;
    }
    double b = 0.0;
    for (int i=0; i<400*20; i++){
        B[i] = b;
        b += 0.001;
    }
    double* C = matmul(A, B, 300, 400, 400, 20);

    for (int i=0; i < 300; i++) {
        for (int j=0; j< 20; j++){
            printf("%f  ", C[i*20+j]);
        }
        printf("\n");
    }
    printf("finished.");

    return 0;
}