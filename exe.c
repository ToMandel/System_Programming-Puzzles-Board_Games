#include <stdio.h>
#include <ctype.h>
#include "exe.h"
#include "sudoku.h"
#include "functions.h"
#include "maxSubMatrix.h"
#include "slidePuzzle.h"

#define ROWS 25
#define COLS 25


void menu()
{
	int rows,cols;
	int subRows,subCols;
	int mat[ROWS][COLS];
	int rowsIndex,colsIndex;
	char input;
	do
	{
		printf("Please choose one of the following options:\n");
		printf("\nS/s - Sudoku");
		printf("\nB/b - Biggest Matrix Sum");
		printf("\nN/n - Game number");
		printf("\nE/e - Quit\n");
		do
		{
			scanf("%c",&input);
			input = toupper(input);
		}while(isspace(input));

		switch(input)
		{

			case 'S':
			{
				int size = chooseSize();
				matrixBuilder((int*)mat,size);
				printMatrix((int*)mat,size,size);
				checkSudoku((int*)mat,size);
				break;
			}

			case 'B':
			{
				printf("Please enter the matrix rows\n");
				rows = setRows(ROWS);
				printf("Please enter the matrix cols\n");
				cols = setCols(COLS);
				initMat((int*)mat,rows,cols);
				printMatrix((int*)mat,rows,cols);
				printf("\nPlease enter the subMatrix rows\n");
				subRows = setRows(rows);
				printf("Please enter the subMatrix cols\n");
				subCols = setCols(cols);
				checkMat((int*)mat,rows,cols,subRows,subCols,&rowsIndex,&colsIndex);
				printSubMatrix((int*)mat,rowsIndex,colsIndex,subRows,subCols,cols);
				printMatrix((int*)mat,rows,cols);
				break;
			}

			case 'N':
			{
				printf("Please enter the puzzle rows\n");
				rows = setRows(ROWS);
				printf("Please enter the puzzle cols\n");
				cols = setCols(COLS);
				initPuzzle((int*)mat,rows,cols);
				printMatrix((int*)mat,rows,cols);
				shuffle((int*)mat,rows,cols);
				printf("\nThe shuffled puzzle: \n");
				printMatrix((int*)mat,rows,cols);
				move((int*)mat,rows,cols);
				break;
			}

		}
	}while(input != 'E');
	printf("Bye Bye\n");
}
