
#ifndef C_LOGISTIC_REGRESSION_DATA_H
#define C_LOGISTIC_REGRESSION_DATA_H

#define IMAGE_SIZE 784


typedef struct {
    double pixels[IMAGE_SIZE];
    int label;
} ImageData;

ImageData* read_csv_batch(FILE* file, int batchsize);
double * get_X(ImageData* image, int batchsize, int num_features);
double * get_y(ImageData* image, int batchsize);


#endif //C_LOGISTIC_REGRESSION_DATA_H
