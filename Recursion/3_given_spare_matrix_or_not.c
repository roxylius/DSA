// to check whether the given matrix is a sparse matrix or not
#include <stdio.h>
#include <stdlib.h>

// checking if the matrix is sparse
int isSparse(int **matrix, int row, int col)
{
    // calculating the number of zeros
    int numOfZeros = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] == 0)
                numOfZeros++;

    int totalElements = row * col;
    int numOfNonZero = totalElements - numOfZeros;

    if (numOfZeros > numOfNonZero)
        return 1;
    else
        return 0;
}

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

    // check if the matrix is sparse or not
    int isMatrixSparse = isSparse(matrix, row, col);

    //printing the given matrix
    printf("\n" );
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%02d  ", matrix[i][j]);

        printf("\n");
    }

    //printing if matrix is sparse or not
    if (isMatrixSparse == 0)
        printf("\n\nThe Given Matrix is NOT SPARSE!" );
    else 
        printf("\n\nThe Given Matrix is SPARSE!" );    

    return 0;
}