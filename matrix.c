#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "helpers.h"

struct Matrix *matrixNew(int rows, int cols)
{

    struct Matrix *matrix = (struct Matrix *)malloc(sizeof(struct Matrix));
    matrix->data = (float *)malloc(sizeof(float) * rows * cols);
    matrix->rows = rows;
    matrix->cols = cols;

    return matrix;
}

boolean matrixHas(struct Matrix *matrix, int x, int y)
{
    return x >= 0 && x < matrix->cols && y >= 0 && y < matrix->rows;
}

int matrixIndex(struct Matrix *matrix, int x, int y)
{
    assert(matrixHas(matrix, x, y), "Coordinates are not within matrix (matrixIndex)\n");
    return (y * matrix->cols) + x;
}

void matrixSetValue(struct Matrix *matrix, int x, int y, float value)
{
    assert(matrixHas(matrix, x, y), "Coordinates are not within matrix (matrixSetValue)\n");
    int i = matrixIndex(matrix, x, y);
    *(float *)(matrix->data + i) = value;
}

float matrixGetValue(struct Matrix *matrix, int x, int y)
{
    assert(matrixHas(matrix, x, y), "Coordinates are not within matrix (matrixGetValue)\n");
    int i = matrixIndex(matrix, x, y);
    return *(float *)(matrix->data + i);
}

void matrixDispose(struct Matrix *matrix)
{
    free(matrix->data);
    free(matrix);
}

struct Matrix * matrixCopy(struct Matrix * matrix) {
    struct Matrix * new_matrix = matrixNew(matrix->rows, matrix->cols);
    int x,y;

    for (x = 0; x < matrix->cols; x++) {
        for (y = 0; y < matrix->rows; y++) {
            matrixSetValue(new_matrix, x,y, matrixGetValue(matrix,x,y));
        }
    }
}

void matrixAddMatrix(struct Matrix * matrix, struct Matrix * other) {
    assert(matrix->cols == other-> cols && matrix->rows == other->cols, "Matrices must be the the same size to add (matrixAddMatrix)");
    int x,y;
    for (x = 0; x < matrix->cols; x++) {
        for (y = 0; y < matrix->rows;y++) {
            matrixSetValue(matrix,x,y,matrixGetValue(matrix,x,y)+matrixGetValue(other,x,y));
        }
    }
}

void matrixAddFloat(struct Matrix * matrix, float value) {
    int x,y;
    for (x = 0; x < matrix->cols; x++) {
        for (y = 0; y < matrix->rows;y++) {
            matrixSetValue(matrix,x,y,matrixGetValue(matrix,x,y)+value);
        }
    }
}

struct Matrix *matrixFromMultiply(struct Matrix *matrix_a, struct Matrix *matrix_b)
{
    assert(matrix_a->cols == matrix_b->rows, "Matrix a cols must equal matrix b rows (matrixMultiply)\n");

    int new_matrix_cols = matrix_b->cols;
    int new_matrix_rows = matrix_a->rows;

    struct Matrix *new_matrix = matrixNew(new_matrix_rows, new_matrix_cols);
    int x, y, i;
    for (x = 0; x < new_matrix_cols; x++)
    {
        for (y = 0; y < new_matrix_rows; y++)
        {
            float new_value = 0.0f;
            for (i = 0; i < matrix_a->cols; i++)
            {
                new_value += matrixGetValue(matrix_a, i, y) * matrixGetValue(matrix_b, x, i);
            }
            matrixSetValue(new_matrix, x, y, new_value);
        }
    }

    return new_matrix;
}

struct Matrix *matrixFromAddition(struct Matrix *matrix_a, struct Matrix *matrix_b)
{
    assert(matrix_a->cols == matrix_b->cols && matrix_a->rows == matrix_b->rows, "Matrices must be the same size (matrixAddtion)\n");

    struct Matrix *new_matrix = matrixCopy(matrix_a);

    matrixAddMatrix(new_matrix, matrix_b);

    return new_matrix;
}