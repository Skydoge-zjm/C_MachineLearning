# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include <activation.h>

double scalar_sigmoid(double a) {
    return (1.0 / (1.0 + exp(-a)));
}

double * sigmoid(double * A, int m, int n) {
    double * outcome = (double *) malloc(m * n * sizeof(double));
    if (outcome == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outcome[i * n + j] = scalar_sigmoid(A[i * n + j]);
        }
    }
    return outcome;
}
