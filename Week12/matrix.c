#include <stdio.h>

void matrixShow (int row, int col, int matrix1[row][col]);
void matrixFill(int row, int col, int matrix1[row][col]);
void matrixEmptier (int row, int col, int matrix1[row][col]);
int matrixSumAll(int row, int col, int matrix1[row][col]);
int martixMultiAll(int row, int col, int matrix1[row][col]);

void matrixEmptier(int row, int col, int matrix1[row][col]){
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			matrix1[i][j] = 0;
		}
	return;
}

void matrixShow (int row, int col, int matrix1[row][col]) {
	int i, j;
	printf("Matrix: \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("[%d] ", matrix1[i][j]);
	printf("\n");
	}
	return;
}

void matrixFill(int row, int col, int matrix1[row][col]){
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			scanf("%d", &matrix1[i][j]);	
			matrixShow(row, col,matrix1);
		}
	return;
}

int matrixSumAll(int row, int col, int matrix1[row][col]){
	int i, j, sum = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			sum += matrix1[i][j];
	}
	return sum;
}

int matrixMultiAll(int row, int col, int matrix1[row][col]){
	int i, j, sum = 1;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			sum *= matrix1[i][j];
	}
	return sum;
}

int main(void) {
	int col, row;
	printf("Please enter the column amount for matrix: ");
	scanf("%d", &col);
	printf("Please enter the row amount for matrix: ");
	scanf("%d", &row);
	printf("Alright Champion, Let's do fill the matrix.\n");
	int matrix1[row][col];
	matrixEmptier(row, col,matrix1);
	matrixShow(row, col,matrix1);
	matrixFill(row, col,matrix1);
	printf("\nDone. Let's do some math!\n");
	printf("Sum of all elements: %d\n", matrixSumAll(row, col, matrix1));
	printf("Multiplication of all elements: %d\n", matrixMultiAll(row, col, matrix1));
	return 0;
}
