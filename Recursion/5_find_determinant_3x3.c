// find determinant of 3x3 matrix
#include <stdio.h>
#include <stdlib.h>

// fn to find determinant of matrix
int determinantOf3x3Matrix(int **matrix, int n)
{
    static int determinant;
    static int col;
    int row = 0; // fixed

    if (col == n)
        return determinant;

    int num[4], index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != row && j != col)
            {
                num[index++] = matrix[i][j];
            }
        }
    }

    if (col == 1)
        determinant -= matrix[row][col++] * ((num[0] * num[3]) - (num[1] * num[2]));
    else
        determinant += matrix[row][col++] * ((num[0] * num[3]) - (num[1] * num[2]));

    determinantOf3x3Matrix(matrix, n);
}

int main()
{
    // row and col of square matrix
    int n = 3;

    // creating dynamically allocated matrix
    int **matrix = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    // taking the value of the matrix
    printf("\nEnter Value of 3x3 Matrix-->\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter a value for Matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // finding determinant of 3x3 sq matrix
    int determinant = determinantOf3x3Matrix(matrix, n);

    //given matrix
    printf("\nThe Given Matrix -->");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%02d  ", matrix[i][j]);

        printf("\n");
    }

    // displaying determinant of matrix
    printf("\nThe Determinant of Matrix: %d", determinant);

    free(matrix);
    return 0;
}