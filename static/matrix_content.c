#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 3

void printMatrix(const char matrix[MATRIX_SIZE][MATRIX_SIZE][20]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%-20s", matrix[i][j]);
        }
        printf("\n");
    }
}

