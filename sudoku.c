#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "sudoku.h"

int chooseSize()
{
	int size;
	float sqrtSize;
	do
	{
		printf("Please enter the Matrix size:\n");
		scanf("%d",&size);
		if(size <= 0)
		{
			printf("size must be greater than 0");
		}
		sqrtSize = sqrt(size);
		if ((sqrtSize -(int)sqrtSize) != 0)
		{
			printf("%d is a NOT perfect squareroot.\n",size);
		}

	} while((sqrtSize -(int)sqrtSize) != 0);
	return size;
}

void matrixBuilder(int* mat,int size)
{
	int i,j,temp;
	printf("Please insert numbers to the Sudoku table:\n");
	printf("The numbers should be less or equal to %d\n",size);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &temp);
			while(temp > size)
			{
				printf("wrong input, please try again\n");
				scanf("%d", &temp);
			}
			*(mat + (i * size + j)) = temp;
		}
	}
}

void checkSudoku(int* mat, int size)
{
	int aux[size+1];
	if(CheckRows((int*)mat,size,(int*)aux)==1 && CheckCols((int*)mat,size,(int*)aux)==1 && checkSubMatrix((int*)mat,size,(int*)aux)==1)
	{
		printf("Success\n");
	}
	else
	{
		printf("Failed\n\n");
	}

}

int CheckRows(int* mat, int size,int* aux)
{
	int i,j,k;
	memset(aux, 0,(size+1)*sizeof(int));
	for (i = 0; i < size; i++)
	{
		for(j = 0;j<size; j++)
		{
			(*(aux + *(mat + (i * size + j))))++;
		}
		for (k = 1; k <= size; k++)
		{
			if(*(aux+k)!=1)
			{
				printf("The value %d came %d time in row %d\n",k,*(aux+k),(i+1));
				return 0;
			}
		}
		//resets the aux array to '0's
		memset(aux, 0,(size+1)*sizeof(int));
	}
	return 1;
}

int CheckCols(int* mat, int size,int* aux)
{
	int i,j,k;
	memset(aux, 0,(size+1)*sizeof(int));
	for (i = 0; i < size; i++)
	{
		for(j = 0;j<size; j++)
		{
			(*(aux + *(mat + (j * size + i))))++;
		}
		for (k = 1; k <= size; k++)
		{
			if(*(aux+k)!=1)
			{
				printf("The value %d came %d time in column %d\n",k,*(aux+k),(i+1));
				return 0;
			}
		}
		//resets the aux array to '0's
		memset(aux, 0,(size+1)*sizeof(int));
	}
	return 1;
}

int checkSubMatrix(int* mat, int size,int* aux)
{
	int i,j,m,b,k,count = 0;
	int sqrtSize = (int)sqrt(size);
	memset(aux, 0,(size+1)*sizeof(int));
	for (m = 0; m < size; m += sqrtSize)
	{
		for(b = 0; b < size; b += sqrtSize)
		{
			for(i = m; i < (m + sqrtSize);i++)
			{
				for(j = b; j < (b + sqrtSize);j++)
				{
					//printf("auxilery status before: %d and the indexs are (%d,%d)\n",*(aux + (*(mat + (i * size + j)))),i,j);
					(*(aux + (*(mat + (i * size + j)))))++;
					//printf("auxilery status after: %d the added number is: %d\n",*(aux + (*(mat + (i * size + j)))),*(mat + (i* size + j)));
				}
			}
			count++;
			for(k=1; k <= size; k++)
			{
				if(*(aux+k)!=1)
				{
					printf("the value %d came %d times in submatrix %d\n",k,*(aux+k),count);
					return 0;
				}
			}
			//resets the aux array to '0's
			memset(aux, 0,(size+1)*sizeof(int));
		}
	}
	return 1;
}
