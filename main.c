#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "misc.h"

int main()
{
    srand (time(NULL));

    matrix mat = generateMatrix();
    printMatrix(mat);
    printf("\n");


    matrix mat2 = generateMatrix();


    printf("\n");
    printMatrix(mat2);


    matrix subbed = subMat(mat, mat);
    printf("\n");
    printMatrix(subbed);

    freeMatrix(mat);
    freeMatrix(mat2);
    freeMatrix(subbed);

    printf("sqrt: = %f", sqroot(2));

    return 0;
}
