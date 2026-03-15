#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findHighestInRow(int** matrix, int row, int col);
void fillTheMatrixRandomly(int** matrix, int row, int col);
void freeTheMatrix(int** matrix, int row);
int** createMatrix(int row, int col);

int main(void)
{
    int row, col;
    srand(time(NULL));
    
    do {
        printf("Please enter the number of rows:");
        scanf("%d", &row);
        printf("Please enter the number of columns:");
        scanf("%d", &col);
        if (row < 1 || col < 1)
        {
            printf("Inputs are invalid for a matrix, please enter meaningful numbers...");
        }
    }
    while (row < 1 || col < 1);

    int** matrix = createMatrix(row, col);

    if (matrix == NULL)
    {
        getchar();
        getchar();
        return 1;
    }

    fillTheMatrixRandomly(matrix, row, col);
    findHighestInRow(matrix, row, col);
    freeTheMatrix(matrix, row);

    getchar();
    getchar();

    return 0;
}

int** createMatrix(int row, int col)
{
    int i;
    int** matrix = malloc(row * sizeof(int*));

    if (matrix == NULL)
    {
        printf("Unfortunately, Memory Allocation is failed. Terminating...");
        return NULL;
    }

    for (i = 0; i < row; i++)
    {
        matrix[i] = malloc(col * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Unfortunately, Memory Allocation is failed. Terminating...");
            freeTheMatrix(matrix, i);
            return NULL;
        }
    }
    
    return (matrix);
}

void fillTheMatrixRandomly(int** matrix, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void findHighestInRow(int** matrix, int row, int col)
{
    int i, j, highest;
    for (i = 0; i < row; i++)
    {
        highest = matrix[i][0];
        for (j = 1; j < col; j++)
        {
            if (highest < matrix[i][j])
            {
                highest = matrix[i][j];
            }
        }
        printf("%d. row's highest is: %d\n", i+1, highest);
    }
    printf("Finding highest for each row order is completed. Thanks for using the program.");
}

void freeTheMatrix(int** matrix, int row)
{
    int i;
    for (i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}