// sort the row of array in ascending order and columns of the matrix in descending order
#include <stdio.h>
int main()
{
    // size of matrix
    int row, col;
    printf("\nEnter the no of rows of matrix: ");
    scanf("%d", &row);
    printf("Enter the no of cols of matrix: ");
    scanf("%d", &col);

    // taiing values for matrix
    int array[row][col];
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter value for matrix[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    //  // sorting rows in descending order
    for (int i = 0; i < row; i++)
    {
        // sorting each individual row
        for (int re = 0; re < col - 1; re++)
        {
            for (int j = 0; j < col - 1 - re; j++)
            {
                if (array[i][j] > array[i][j + 1])
                {
                    int temporary = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = temporary;
                }
            }
        }
    }

    //  // sorting cols in descending order
    for (int j = 0; j < col; j++)
    {
        // sorting each individual columns
        for (int re = 0; re < row - 1; re++)
        {
            for (int i = 0; i < row - 1 - re; i++)
            {
                if (array[i][j] < array[i + 1][j])
                {
                    int temp = array[i][j];
                    array[i][j] = array[i + 1][j];
                    array[i + 1][j] = temp;
                }
            }
        }
    }

    // printing the desired matrix
    printf("\nThe desired Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        printf("\t\t    ");
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}