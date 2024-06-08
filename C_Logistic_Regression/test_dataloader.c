#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "data.h"

int main_test_dataloader()
{
    int batchsize = 5;
    const char* file_name = "../data/mnist_train_filtered.csv";
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Cannot open file");
        return 1;
    }
    ImageData* images = read_csv_batch(file, batchsize);
    for(int i=0; i<IMAGE_SIZE; i++){
        printf("%f,", images[0].pixels[i]);
    }
    for (int i = 0; i<batchsize; i++){
        printf("\nLabel: %d", images[i].label);
    }

    free(images);
    return 0;
}