#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "slidePuzzle.h"
#include "functions.h"

#define SHUFFLE_COUNT 30

void	initPuzzle(int* mat,int rows,int cols)
{
  int i, j;
  printf("Entering %d numbers to puzzle\n", cols*rows);
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      *(mat + (i * cols + j)) = ((i*cols + j)+1);
    }
  }
  *(mat + ((rows * cols)-1)) = 0;
}

void findZero(int* mat,int rows,int cols, int* rowsIndex,int* colsIndex)
{
  int i,j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      if(*(mat + (i * cols + j))==0)
      {
        *rowsIndex = i;
        *colsIndex = j;
      }
    }
  }
}


void shuffle(int* mat,int rows, int cols)
{
  int k,temp,rowsIndex,colsIndex;
  srand(time(NULL));
  for(k=0; k < SHUFFLE_COUNT; k++)
  {
    findZero((int*)mat,rows,cols,&rowsIndex,&colsIndex);
    temp = 1 + (rand() % (4 - 1 +1));
    if(temp == 1)
    {
      moveUp((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    if(temp == 2)
    {
      moveDown((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    if(temp == 3)
    {
      moveLeft((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    if(temp == 4)
    {
      moveRight((int*)mat,cols,&rowsIndex,&colsIndex);
    }
  }
}


void move(int* mat,int rows,int cols)
{
  int numInput,rowsIndex,colsIndex;
  do{
    findZero((int*)mat,rows,cols,&rowsIndex,&colsIndex);
    printf("Your Step:\n");
    scanf("%d",&numInput);
    if((*(mat + (rowsIndex*cols +(colsIndex-1)))) == numInput)
    {
      moveRight((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    else if((*(mat + (rowsIndex*cols +(colsIndex+1))))== numInput)
    {
      moveLeft((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    else if((*(mat + ((rowsIndex-1)*cols +colsIndex)))== numInput)
    {
      moveUp((int*)mat,cols,&rowsIndex,&colsIndex);
    }
    else if((*(mat + ((rowsIndex+1)*cols +colsIndex)))== numInput)
    {
      moveDown((int*)mat,cols,&rowsIndex,&colsIndex);
    }else
    {
      printf("Invalid step\n");
    }
    printMatrix((int*)mat,rows,cols);
  }while(checkForFinish((int*)mat,rows,cols)!=1);
}

void moveRight(int* mat,int cols,int* rowsIndex,int* colsIndex)
{
  int temp;
  temp = *(mat + ((*rowsIndex)*cols +((*colsIndex)-1)));
  *(mat + ((*rowsIndex) * cols +((*colsIndex)-1))) = 0;
  *(mat + ((*rowsIndex) * cols + (*colsIndex))) = temp;
}

//moves the number to the left
void moveLeft(int* mat,int cols,int* rowsIndex,int* colsIndex)
{
  int temp;
  temp = *(mat + ((*rowsIndex)*cols +((*colsIndex)+1)));
  *(mat + ((*rowsIndex)* cols +((*colsIndex)+1))) = 0;
  *(mat + ((*rowsIndex)* cols + (*colsIndex))) = temp;
}

//moves the number up
void moveUp(int* mat,int cols,int* rowsIndex,int* colsIndex)
{
  int temp;
  temp = *(mat + (((*rowsIndex)-1)*cols +(*colsIndex)));
  *(mat + (((*rowsIndex)-1)*cols +(*colsIndex))) = 0;
  *(mat + ((*rowsIndex)*cols +(*colsIndex))) = temp;
}

//moves the number down
void moveDown(int* mat,int cols,int* rowsIndex,int* colsIndex)
{
  int temp;
  temp = *(mat + (((*rowsIndex)+1)*cols +(*colsIndex)));
  *(mat + (((*rowsIndex)+1)*cols +(*colsIndex))) = 0;
  *(mat + ((*rowsIndex)*cols +(*colsIndex))) = temp;
}

//function used to spot a winning board
int checkForFinish(int* mat,int rows,int cols)
{
  int i,j,temp,result;
  result = 0;
  temp = 1;
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if (*(mat + (i * cols + j)) == temp)
      {
        temp += 1;
      }
    }
  }
  if (temp == cols*rows && *(mat+(cols*rows-1))== 0)
  {
    result = 1;
    printf("You Win! The game is over!\n");
    return result;
  }
  return result;
}
