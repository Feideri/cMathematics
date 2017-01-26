#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

unsigned int generateInteger(){
    return rand() % 5 + 1;
}

int generateVal(){
    return rand() % 31 + (-15);
}

matrix generateFixedMatrix(unsigned int rows, unsigned int cols){

    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.elements = (float**) malloc(rows*sizeof(float*));
    short cAlloc = 0;

    //check allocation
    while(cAlloc == 0){
            if(m.elements == NULL){
                free(m.elements);
                m.elements = (float**) malloc(m.rows * sizeof(float*));
                cAlloc = 0;
            }
            else
                cAlloc = 1;
    }


    for(unsigned int i = 0; i < rows;i++)
            m.elements[i] = (float*) malloc(cols*sizeof(float));

    cAlloc = 0;
    //check allocation
    while(cAlloc == 0){
        cAlloc = 1;

        for(unsigned int i = 0; i < m.rows;i++)
            if(m.elements[i] == NULL){
                cAlloc = 0;
        }

        if(cAlloc == 0){
           for(unsigned int i = 0; i < m.rows;i++)
                free(m.elements[i]);

           for(unsigned int i = 0; i < m.rows;i++)
                m.elements[i] = (float*) malloc(m.cols*sizeof(float));

        }

    }

    return m;

}

matrix generateMatrix(){
    unsigned int row = generateInteger();
    unsigned int col = generateInteger();
    matrix m = generateFixedMatrix(row, col);

    for(unsigned int i = 0; i < row; i++)
        for(unsigned int k = 0; k < col; k++)
            m.elements[i][k] = (float)generateVal();

    return m;
}

matrix generateIdentity(unsigned int n){
    matrix m = generateFixedMatrix(n, n);

    for(unsigned int i = 0; i < m.rows; i++)
        for(unsigned int k = 0; k < m.cols; k++){
            if(i == k)
                m.elements[i][k] = 1;
            else
                m.elements[i][k] = 0;
        }

    return m;
}

void printMatrix(matrix m){

    for(unsigned int i = 0; i < m.rows; i++){
        for(unsigned int k = 0; k < m.cols; k++)
            printf("%3.2f\t", m.elements[i][k]);
        printf("\n");
    }
}

matrix mulMat(matrix m1, matrix m2){

    if(m1.cols != m2.rows){
        printf("Dimensions do not match for the multiplication.\n");
        matrix ret = generateFixedMatrix(1,1);
        ret.elements[0][0] = 0;

        return ret;

    }

    matrix mul;
    mul.rows = m1.rows;
    mul.cols = m2.cols;

    mul.elements = (float**) malloc(mul.rows * sizeof(float*));

    short cAlloc = 0;
    //check allocation
    while(cAlloc == 0){
            if(mul.elements == NULL){
                free(mul.elements);
                mul.elements = (float**) malloc(mul.rows * sizeof(float*));
                cAlloc = 0;
            }
            else
                cAlloc = 1;
    }

    for(unsigned int i = 0; i < mul.rows;i++)
        mul.elements[i] = (float*) malloc(mul.cols*sizeof(float));

    cAlloc = 0;
    //check allocation
    while(cAlloc == 0){
        cAlloc = 1;

        for(unsigned int i = 0; i < mul.rows;i++)
            if(mul.elements[i] == NULL){
                cAlloc = 0;
        }

        if(cAlloc == 0){
           for(unsigned int i = 0; i < mul.rows;i++)
                free(mul.elements[i]);

           for(unsigned int i = 0; i < mul.rows;i++)
                mul.elements[i] = (float*) malloc(mul.cols*sizeof(float));

        }

    }

    for(unsigned int i = 0; i < mul.rows;i++)
        for(unsigned int j = 0; j < mul.cols;j++){
            mul.elements[i][j] = 0;
            for(unsigned int k = 0; k < m1.cols;k++)
                mul.elements[i][j] += (float) m1.elements[i][k] * (float) m2.elements[k][j];
        }
    return mul;
}

matrix addMat(matrix m1, matrix m2){
    matrix ret;
    if(m1.rows != m2.rows || m1.cols != m2.cols){
        printf("Dimensions differ!\n");
        ret = generateFixedMatrix(1,1);
        ret.elements[0][0] = 0;
        return ret;
    }

    ret = generateFixedMatrix(m1.rows, m1.cols);
    for(unsigned int i = 0; i < m1.rows; i++)
        for(unsigned int j = 0; j < m1.cols;j++)
            ret.elements[i][j] = m1.elements[i][j] + m2.elements[i][j];

    return ret;

}

matrix subMat(matrix m1, matrix m2){
    matrix ret;
    if(m1.rows != m2.rows || m1.cols != m2.cols){
        printf("Dimensions differ!\n");
        ret = generateFixedMatrix(1,1);
        ret.elements[0][0] = 0;
        return ret;
    }

    ret = generateFixedMatrix(m1.rows, m1.cols);
    for(unsigned int i = 0; i < m1.rows; i++)
        for(unsigned int j = 0; j < m1.cols;j++)
            ret.elements[i][j] = m1.elements[i][j] - m2.elements[i][j];

    return ret;

}

matrix transpose(matrix m){
    int rows = m.cols;
    int cols = m.rows;

    matrix n = generateFixedMatrix(rows, cols);

    for(int i = 0; i < rows;i++)
        for(int k = 0; k < cols;k++)
            n.elements[i][k] = m.elements[k][i];

    return n;
}

void freeMatrix(matrix m){

    for(unsigned int i = 0; i < m.rows;i++)
                free(m.elements[i]);
    free(m.elements);
}
