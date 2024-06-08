#ifndef C_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_H
#define C_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_H



void initialize_weights(double* weights, int m, int n);
double * train(FILE* file, double* weights, int batchsize, int num_features, int num_iterations, double learning_rate);

#endif //C_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_H
