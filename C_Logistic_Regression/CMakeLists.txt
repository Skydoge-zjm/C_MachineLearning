cmake_minimum_required(VERSION 3.27)
project(C_Logistic_Regression C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Logistic_Regression
        data.h
        data.c
        logistic_regression.c
        logistic_regression.h
        matrix_calculation/matrix_multiply.c
        matrix_calculation/matrix_multiply.h
        matrix_calculation/test_matmul.c
        test_dataloader.c
        matrix_calculation/matrix_transpose.c
        matrix_calculation/matrix_transpose.h
        matrix_calculation/test_transpose.c
        matrix_calculation/matrix.h
        function_on_matrix/activation.c
        function_on_matrix/activation.h
        function_on_matrix/loss_function.h
        function_on_matrix/loss_funciton.c
        matrix_calculation/matrix_linear.c
        matrix_calculation/matrix_linear.h
        gradient_decent.c
        gradient_decent.h
)
