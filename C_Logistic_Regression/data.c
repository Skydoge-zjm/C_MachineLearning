#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "data.h"


int get_line_count(FILE* file) {
    int count = 0;
    char line[4096];
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    rewind(file); // 回到文件开头
    return count;
}

ImageData* read_csv_batch(FILE* file, int batchsize) {
    int line_count = get_line_count(file); // 获取文件中的行数
    // printf("line count: %d\n", line_count);
    if (line_count <= 1) {
        return NULL;
    }

    ImageData* images = (ImageData*)malloc(batchsize * sizeof(ImageData));
    if (images == NULL) {
        perror("Cannot allocate memory");
        exit(1);
    }

    char line[4096];


    // 生成随机行号
    int* random_lines = (int*)malloc(batchsize * sizeof(int));
    if (random_lines == NULL) {
        perror("Cannot allocate memory for random lines");
        free(images);
        exit(1);
    }

    srand((unsigned)time(NULL));
    for (int i = 0; i < batchsize; i++) {

        int line_index = rand() % (line_count - 1) + 1;
        //printf("line index: %d\n", line_index);
        random_lines[i] = line_index; // 生成随机行号
    }

    // 读取随机行
    for (int i = 0; i < batchsize; i++) {
        if(fseek(file, random_lines[i] * sizeof(line), SEEK_SET) != 0){
            printf("Error: Fail to seek line %d.\n", random_lines[i]);
            exit(1);
        } // 跳转到随机行
        rewind(file);
        for (int j = 0; j < random_lines[i]-1; j++) {
            fgets(line, sizeof(line), file);
        }
        char * p = fgets(line, sizeof(line), file);
        if (p == NULL) { // 读取行
            printf("Error: Fail to read line %d\n", random_lines[i]);
            exit(2);
        }

        char* token = strtok(line, ",");
        for (int j = 0; j < IMAGE_SIZE; j++) {
            char* end_ptr;
            images[i].pixels[j] = strtod(token, &end_ptr);
            if (end_ptr == token) {
                printf("Fail to String -> double, in line %d pixel %d.\n", random_lines[i], j);
                exit(1);
            }
            token = strtok(NULL, ",");
        }
        char* end_ptr;
        if (end_ptr == token) {
            //printf("Fail to String -> double, in line %d label.\n", random_lines[i]);
            //exit(1);
        }
        images[i].label = (int)strtol(token, &end_ptr, 10);
    }

    free(random_lines); // 释放随机行号数组的内存
    return images; // 返回指向 ImageData 数组的指针
}

double * get_X(ImageData* image, int batchsize, int num_features) {
    int m = batchsize;
    int n = num_features + 1;
    double * X = (double *) malloc(m * n * sizeof(double));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(j < num_features) {
                X[i * n + j] = image[i].pixels[j];
            } else {
                X[i * n + j] = 1.0;
            }
        }
    }
    return X;
}

double * get_y(ImageData* image, int batchsize) {
    int m = batchsize;
    double * y = (double *) malloc(m * 1 * sizeof(double));
    for (int i = 0; i < m; i++) {
        y[i] = image[i].label;
    }
    return y;
}
