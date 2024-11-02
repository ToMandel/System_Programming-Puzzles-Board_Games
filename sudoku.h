#ifndef __SUD__
#define __SUD__

int chooseSize();
void matrixBuilder(int* mat,int size);
void checkSudoku(int* mat, int size);
int CheckRows(int* mat, int size,int* aux);
int CheckCols(int* mat, int size,int* aux);
int checkSubMatrix(int* mat, int size,int* aux);

#endif
