#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct{
    int rows;
    int cols;
    float **elements;

}matrix;

unsigned int generateInteger();
int generateVal();
matrix generateFixedMatrix(unsigned int rows, unsigned int cols);
matrix generateMatrix();
matrix generateIdentity(unsigned int n);
void printMatrix(matrix m);
matrix multiplication(matrix m1, matrix m2);
matrix transpose(matrix m);
void freeMatrix(matrix m);

#endif // MATRIX_H_INCLUDED
