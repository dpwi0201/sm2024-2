#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int A[ROWS][COLS] = {
		{2, 3, 0},
		{8, 9, 1},
		{7, 0, 5}};
		
	int B[ROWS][COLS] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}};
	
	int C[ROWS][COLS];
	
	addMatrix(A, B, C);
	printMatrix(C);

	return 0;
}

int addMatrix(int x[ROWS][COLS], int y[ROWS][COLS], int z[ROWS][COLS])
{
	int i, j;
	
	for(i=0;i<ROWS;i++)
		for(j=0;j<COLS;j++)
			z[i][j] = x[i][j] + y[i][j];
}

int printMatrix(int a[ROWS][COLS])
{
	printf("%d %d %d\n", a[0][0], a[0][1], a[0][2]);
	printf("%d %d %d\n", a[1][0], a[1][1], a[1][2]);
	printf("%d %d %d\n", a[2][0], a[2][1], a[2][2]);	
}