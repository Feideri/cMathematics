#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main()
{
    srand (time(NULL));

    matrix mat = generateMatrix();
    printMatrix(mat);
    printf("\n");


    matrix mat2 = generateMatrix();


    printf("\n");
    printMatrix(mat2);


    matrix multiplied = multiplication(mat, mat2);
    printf("\n");
    printMatrix(multiplied);

    freeMatrix(mat);
    freeMatrix(mat2);
    freeMatrix(multiplied);


    return 0;
}
