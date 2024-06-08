
#ifndef C_LOGISTIC_REGRESSION_LOSS_FUNCTION_H
#define C_LOGISTIC_REGRESSION_LOSS_FUNCTION_H

double * cross_entropy_loss(double * y_true, double * y_pred, int m);
double ave_loss(double * loss, int m);

#endif //C_LOGISTIC_REGRESSION_LOSS_FUNCTION_H
