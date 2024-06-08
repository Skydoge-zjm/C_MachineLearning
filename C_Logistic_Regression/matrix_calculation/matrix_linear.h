
#ifndef C_LOGISTIC_REGRESSION_MATRIX_LINEAR_H
#define C_LOGISTIC_REGRESSION_MATRIX_LINEAR_H

double * add_scalar(double * A, int m, int n, double x);
double * add_matrix(double * A, double * B, int m1, int n1, int m2, int n2);
double * scalar_mul(double * A, int m, int n, double x);
double * linear_matrix(double * A, double * B, int m1, int n1, int m2, int n2, double x1, double x2);


#endif //C_LOGISTIC_REGRESSION_MATRIX_LINEAR_H
