#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"

#define MAX_SIZE 25

void printMatrix(int* mat,int rows,int cols)
{
	printf("\nHere is your Matrix:\n");
	int i, j;
	for (i = 0; i < rows;i++)
	{
		for (j = 0;j < cols ;j++)
		{
			printf("%3d ", *mat);
			mat++;
		}
		printf("\n");
	}
}
void printSubMatrix(int* mat,int rowsIndex,int colsIndex,int subRow,int subCol,int cols)
{
	printf("\nHere is your SubMatrix:\n");
	int k,m;
	k = subRow;

	for (int i = rowsIndex ; k > 0 ;k--,i++)
	{
		m = subCol;
		for (int j = colsIndex ; m > 0 ;m--,j++)
		{
			printf("%3d ", *(mat + (i * cols + j)));


		}
		printf("\n");
	}
}

int setRows(int rows)
{
	int temp;
	do
	{
		printf("rows must be less than %d rows and greater than 1\n",rows);
		scanf("%d",&temp);
		if (temp < 1 || temp > rows)
		{
			printf("Wrong input\n");
		}
	} while(temp < 1 || temp > rows);
	printf("the rows number is: %d\n",temp);
	return temp;
}

int setCols(int cols)
{
	int temp;
	do
	{
		printf("cols must be less than %d cols and greater than 1\n",cols);
		scanf("%d",&temp);
		if (temp < 1 || temp > cols)
		{
			printf("Wrong input\n");
		}
	} while(temp < 1 || temp > cols);
	printf("the cols number is: %d\n",cols);
	return temp;
}
