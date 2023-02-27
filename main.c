#include <stdio.h>
#include "matrix.h"


int main()
{

    struct Matrix * matrix = matrixNew(2,2);

    matrixSetValue(matrix,0,0,1.0f);
    matrixSetValue(matrix,0,1,0.1f);
    matrixSetValue(matrix,1,0,0.5f);
    matrixSetValue(matrix,1,1,2.0f);

    struct Matrix * matrix_b = matrixNew(2,1);

    matrixSetValue(matrix_b,0,0,2.0f);
    matrixSetValue(matrix_b,0,1,5.0f);

    struct Matrix * mult_matrix = matrixMultiply(matrix,matrix_b);

    printf("value : %f\n", matrixGetValue(mult_matrix,0,0));
    printf("value : %f\n", matrixGetValue(mult_matrix,0,1));

    matrixDispose(matrix);
    matrixDispose(matrix_b);
    matrixDispose(mult_matrix);
}