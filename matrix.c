#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


struct Matrix * matrixNew(int rows, int cols) {

    struct Matrix * matrix = (struct Matrix *)malloc(sizeof(struct Matrix));
    matrix->data = (float *)malloc(sizeof(float)*rows*cols);
    matrix->rows = rows;
    matrix->cols = cols;

    return matrix;
}

int matrixIndex(int cols, int x, int y)
{
    return (y*cols) + x;
}


void matrixSetValue(struct Matrix * matrix, int x, int y, float value) 
{
    int i = matrixIndex(matrix->cols, x, y);
    *( float *)(matrix->data + i) = value;
}

float matrixGetValue(struct Matrix * matrix, int x, int y)
{
    int i = matrixIndex(matrix->cols, x, y);
    return * (float *)(matrix->data + i);
}

void matrixDispose(struct Matrix * matrix)
{
    free(matrix->data);
    free(matrix);
}

struct Matrix * matrixMultiply(struct Matrix * matrix_a, struct Matrix * matrix_b)
{
    if (matrix_a->cols != matrix_b -> rows){
        printf("Matrix a cols must equal matrix b rows");
        exit(1);
    }

    int new_matrix_cols = matrix_b -> cols;
    int new_matrix_rows = matrix_a -> rows;

    struct Matrix * new_matrix = matrixNew(new_matrix_rows, new_matrix_cols);
    int x,y,i;
    for (x = 0; x < new_matrix_cols; x++) {
        for (y = 0; y < new_matrix_rows; y++) {
            float new_value = 0.0f;
            for (i = 0; i < matrix_a->cols; i++) {
                new_value += matrixGetValue(matrix_a,i,y)*matrixGetValue(matrix_b,x,i);
            }
            matrixSetValue(new_matrix, x, y, new_value);
        }
    }

    return new_matrix;
}