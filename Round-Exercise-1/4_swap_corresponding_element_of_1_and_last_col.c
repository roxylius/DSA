// swap corresponding elements of 1st and last column and 2nd & 2nd last in a matrix

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

    // printing the entered matrix
    printf("\n\nThe desired Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        printf("\t\t    ");
        for (int j = 0; j < col; j++)
        {
            printf("%02d  ", array[i][j]);
        }
        printf("\n");
    }

    // swapping element of 1st and last col and respectively
    for (int c = 0; c < col / 2; c++)
    {
        for (int r = 0; r < row; r++)
        {
            int temp = array[r][c];
            array[r][c] = array[r][col - 1 - c];
            array[r][col - 1 - c] = temp;
        }
    }

    // printing the desired matrix
    printf("\n\nThe desired Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        printf("\t\t    ");
        for (int j = 0; j < col; j++)
        {
            printf("%02d  ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}