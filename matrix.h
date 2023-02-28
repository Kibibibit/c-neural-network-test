#ifndef MATRIX_H
#define MATRIX_H

#include "linked_list.h"
#include "helpers.h"

struct Matrix
{
    float *data;
    int rows;
    int cols;
};

struct Matrix *matrixNew(int rows, int cols);

boolean matrixHas(struct Matrix *matrix, int x, int y);

int matrixIndex(struct Matrix *matrix, int x, int y);

void matrixSetValue(struct Matrix *matrix, int x, int y, float value);

float matrixGetValue(struct Matrix *matrix, int x, int y);

struct Matrix *matrixCopy(struct Matrix *matrix);

/*
Add matrix `other` to `matrix`. Updates `matrix` and returns void
*/
void matrixAddMatrix(struct Matrix *matrix, struct Matrix *other);

/*
Returns a new matrix from the result of multiplication of matrix_a*matrix_b
*/
struct Matrix *matrixFromMultiply(struct Matrix *matrix_a, struct Matrix *matrix_b);

/*
Returns a new matrix from the result of matrix_a + matrix_b
*/
struct Matrix *matrixFromAddition(struct Matrix *matrix_a, struct Matrix *matrix_b);

/*
Adds `value` to all values in the matrix.
*/
void matrixAddFloat(struct Matrix *matrix, float value);

/*
Multiplies all values in the matrix by `value`
*/
void matrixMultiplyFloat(struct Matrix *matrix, float value);

void matrixDispose(struct Matrix *matrix);

void matrixRandomize(struct Matrix *matrix, float min, float max);

#endif