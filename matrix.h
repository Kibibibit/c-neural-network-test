#ifndef MATRIX_H
#define MATRIX_H

#include "linked_list.h"

struct Matrix 
{
    float * data;
    int rows;
    int cols;
};

struct Matrix * matrixNew(int rows, int cols);

int matrixIndex(struct Matrix * matrix, int x, int y);

void matrixSetValue(struct Matrix * matrix, int x, int y, float value);

float matrixGetValue(struct Matrix * matrix, int x, int y);

struct Matrix * matrixMultiply(struct Matrix * matrix_a, struct Matrix * matrix_b);

void matrixDispose(struct Matrix * matrix);

#endif