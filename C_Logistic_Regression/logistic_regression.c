#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "data.h"
#include "logistic_regression.h"
#include "gradient_decent.h"
#include "matrix_calculation/matrix.h"
#include "function_on_matrix/activation.h"
#include "function_on_matrix/loss_function.h"


void initialize_weights(double* weights, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            weights[i * n + j] = 1.0;
        }
    }
}

// Train the logistic regression model using gradient descent
double * train(FILE* file, double* weights, int batchsize, int num_features, int num_iterations, double learning_rate) {

    for (int iter = 0; iter < num_iterations; iter++) {
        ImageData* images = read_csv_batch(file, batchsize);
        double * X = get_X(images, batchsize, IMAGE_SIZE);
        double * y_true = get_y(images, batchsize);
        double * y_pred = sigmoid(matmul(X, weights, batchsize, num_features+1, num_features+1, 1) ,batchsize ,1);
        weights = gradient_decent(weights, X, y_true, y_pred, batchsize, IMAGE_SIZE, learning_rate);
        /*
        for (int i = 0; i < batchsize; i++) {
            printf("%.3f ", weights[i]);
        }
         */

        double * loss = cross_entropy_loss(y_true, y_pred, batchsize);
        double loss_ave = ave_loss(loss, batchsize);
        printf("Epoch: %d  Loss: %f\n", iter, loss_ave);

        if ((iter + 1) % 10 == 0){
            printf("Train %d epoch\n", iter + 1);
        }
    }
    return weights;
}

void predict(FILE * file, double * weights, int batchsize, int num_features) {
    ImageData* images = read_csv_batch(file, batchsize);
    double * X = get_X(images, batchsize, IMAGE_SIZE);
    double * y_true = get_y(images, batchsize);
    double * y_pred = sigmoid(matmul(X, weights, batchsize, num_features+1, num_features+1, 1) ,batchsize ,1);
    int sum = 0;
    for (int i = 0; i < batchsize; i++) {
        printf("Prediction: %.3f", y_pred[i]);
        printf("  True: %.3f  ", y_true[i]);
        if (fabs(y_true[i] - y_pred[i]) < 0.5) {
            sum++;
            printf("Correct\n");
        } else {
            printf("Wrong\n");
        }

    }
    printf("Accuracy: %d/%d", sum, batchsize);
}

int main() {
    const char* file_train = "../data/mnist_train_filtered.csv";
    FILE* file = fopen(file_train, "r");
    if (file == NULL) {
        perror("Cannot open file");
        return 1;
    }
    int batch_size = 16;
    int num_features = IMAGE_SIZE;
    double * weights = (double *) malloc(1 * (IMAGE_SIZE + 1) * sizeof(double));

    initialize_weights(weights, 1, IMAGE_SIZE + 1);

    int num_iterations = 20;
    double learning_rate = 0.1;
    weights = train(file, weights, batch_size, num_features, num_iterations, learning_rate);

    fclose(file);

    const char* file_test = "../data/mnist_test_filtered.csv";
    batch_size = 100;
    file = fopen(file_test, "r");
    predict(file, weights, batch_size, num_features);

    return 0;
}