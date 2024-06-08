# include <stdio.h>
# include <stdlib.h>

#include "matrix_transpose.h"

int main_test_transpose()
{
    double* A = (double *) malloc(4*3*sizeof(double));
    double a = 0.0;
    for (int i=0; i<4*3; i++){
        A[i] = a;
        a += 0.1;
    }
    for (int i=0; i < 4; i++) {
        for (int j=0; j< 3; j++){
            printf("%f  ", A[i*3+j]);
        }
        printf("\n");
    }
    printf("AT = \n");
    double * AT = transpose(A, 4, 3);
    for (int i=0; i < 3; i++) {
        for (int j=0; j< 4; j++){
            printf("%f  ", AT[i*4+j]);
        }
        printf("\n");
    }
    free(A);
    return 0;
}