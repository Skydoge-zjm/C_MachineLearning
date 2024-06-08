# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "loss_function.h"

double cross_entropy_loss_on_scalar(double y_true, double y_pred) {
    if (y_true == 1) {
        if (y_pred - 0 < 0.00000001) {
            y_pred = 0.00000001;
        }
        return -log(y_pred);
    } else if (y_true == 0) {
        if (1 - y_pred < 0.00000001) {
            y_pred = 0.99999999;
        }
        return -log(1 - y_pred);
    } else {
        printf("Warning: Input of cross_entropy is not 0/1.");
        exit(3);
    }
}

double * cross_entropy_loss(double * y_true, double * y_pred, int m) {
    double * loss = (double *) malloc(m * 1 * sizeof(double));
    for (int i = 0; i < m; i++) {
        loss[i] = cross_entropy_loss_on_scalar(y_true[i], y_pred[i]);
    }
    return loss;
}

double ave_loss(double * loss, int m) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        sum += loss[i];
    }
    sum = sum / m;
    return sum;
}
