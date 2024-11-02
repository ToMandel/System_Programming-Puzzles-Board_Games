#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "maxSubMatrix.h"


#define MAX_NUM 45
#define MIN_NUM -45

void	initMat(int* mat,int rows,int cols)
{
  int i, j;
  srand(time(NULL));
  printf("Entering %d numbers to matrix\n", cols*rows);
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      *(mat + (i * cols + j)) = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM+1));
    }
  }
}

void checkMat(int* mat,int rows,int cols,int subRows,int subCols,int* tempRow,int* tempCol)
{
  int tempSum,i,j,k,h,n,m;
  int sum = -1000;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      for (k = i; k < subRows+i && k < rows; k++)
      {
        for(h = j; h < subCols+j && h < cols; h++)
        {
          tempSum = 0;
          for (m = i; m <= k; m++)
          {
            for(n = j; n <= h; n++)
            {
              tempSum += *(mat + (m * cols + n));
            }
          }
          if(sum < tempSum)
          {
            sum = tempSum;
            *tempRow = i;
            *tempCol = j;
          }
        }
      }
    }
  }

}
