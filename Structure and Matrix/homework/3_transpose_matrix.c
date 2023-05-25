// find the transpose of matrix
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter the no of rows in matrix = ");
    scanf("%d", &row);
    printf("Enter the no of columns in matrix =  ");
    scanf("%d", &col);
    printf("\n");

    // creating dynamically allocated matrix
    int **matrix = (int **)malloc(row * sizeof(int));
    for (int i = 0; i < row; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    // taking the value of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter a value for Matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // creating a new dynamically allocated matrix
    int newRow = col;
    int newCol = row;
    int **matrixNew = (int **)malloc(newRow * sizeof(int));
    for (int i = 0; i < newRow; i++)
        matrixNew[i] = (int *)malloc(newCol * sizeof(int));

    // transposing matrix
    for (int i = 0; i < newRow; i++)
    {
        for (int j = 0; j < newCol; j++)
        {
            matrixNew[i][j] = matrix[j][i];
        }
    }

    // printing the given matrix
    printf("\nThe Given Matrix -->");
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%02d  ", matrix[i][j]);

        printf("\n");
    }

    // printing the new matrix
    printf("\nThe Transpose of the matrix -->");
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%02d  ", matrix[i][j]);

        printf("\n");
    }

    return 0;
}