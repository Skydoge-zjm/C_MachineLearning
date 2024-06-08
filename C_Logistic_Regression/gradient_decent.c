# include <stdio.h>
# include <stdlib.h>

# include "matrix_calculation/matrix.h"
# include "function_on_matrix/activation.h"

double* gradient_decent(double * w, double * X, double * y_true, double * y_pred,
                     int batchsize, int num_features, double learning_rate) {

    int b = batchsize;
    int n = num_features + 1;

    double * grad_m = matmul(transpose(X, b, n), linear_matrix(y_pred, y_true, n, 1, n, 1, 1, -1), n, b, b, 1);
    w = linear_matrix(w, grad_m, n, 1, n, 1, 1, -(learning_rate / b));
    return w;
}