
#ifndef C_LOGISTIC_REGRESSION_GRADIENT_DECENT_H
#define C_LOGISTIC_REGRESSION_GRADIENT_DECENT_H

double * gradient_decent(double * w, double * X, double * y_true, double * y_pred,
                     int batchsize, int num_features, double learning_rate);



#endif //C_LOGISTIC_REGRESSION_GRADIENT_DECENT_H
