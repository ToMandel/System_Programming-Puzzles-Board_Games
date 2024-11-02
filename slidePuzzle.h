#ifndef PUZ__
#define PUZ__

void	initPuzzle(int* mat,int rows,int cols);
void findZero(int* mat,int rows,int cols, int* rowsIndex,int* colsIndex);
void shuffle(int* mat,int rows,int cols);
void move(int* mat,int rows,int cols);
void moveRight(int* mat,int cols,int* rowsIndex,int* colsIndex);
void moveLeft(int* mat,int cols,int* rowsIndex,int* colsIndex);
void moveUp(int* mat,int cols,int* rowsIndex,int* colsIndex);
void moveDown(int* mat,int cols,int* rowsIndex,int* colsIndex);
int checkForFinish(int* mat,int rows,int cols);

#endif
