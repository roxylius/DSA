// wap a program to determine whether the given matrix is lower triangular or upper triangular or tri triangular matrix
#include <stdio.h>
#include <stdlib.h>

int isLowerMatrix(int **matrix, int sideLength)
{
    int isLower = 1;
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = i + 1; j < sideLength; j++)
        {
            if (matrix[i][j] != 0)
                isLower = 0;
        }
    }

    return isLower;
}

int isUpperMatrix(int **matrix, int sideLength)
{
    int isUpper = 1;
    for (int i = 1; i < sideLength; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != 0)
                isUpper = 0;
        }
    }
    return isUpper;
}

int isTriDiagonalMatrix(int **matrix, int sideLength)
{
    int isTridigonal = 1;

    // lower half
    for (int i = 2; i < sideLength; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (matrix[i][j] != 0)
                isTridigonal = 0;

            // //fixing an issue
            // printf("\n````matrix[%d][%d]: %d```\n",i,j,matrix[i][j]);
            // printf("\n````%d```\n",isTridigonal);            
        }
    }

    // upper half
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 2 + i; j < sideLength; j++)
        {
            if (matrix[i][j] != 0)
                isTridigonal = 0;

            //testing some issue
            // printf("\n````matrix[%d][%d]: %d````\n",i,j,matrix[i][j]);
            // printf("\n````%d```\n",isTridigonal);            
        }
    }

    return isTridigonal;
}

int isNullMatrix(int **matrix,int sideLength){
    int isNull = 1;
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < sideLength; j++)
        {
            if (matrix != 0)
                isNull = 0;
        }
    }

    return isNull;
}

int main()
{
    int sideLength;
    printf("Enter the no of rows and col in square matrix = ");
    scanf("%d", &sideLength);
    printf("\n");

    // creating dynamically allocated matrix
    int **matrix = (int **)malloc(sideLength * sizeof(int));
    for (int i = 0; i < sideLength; i++)
        matrix[i] = (int *)malloc(sideLength * sizeof(int));


    // taking values of matrix
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < sideLength; j++)
        {
            printf("Enter the value of matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    //printing the given matrix
    printf("\n\nThe given matrix->\n" );
    for (int i = 0; i < sideLength; i++)
    {
        for (int j = 0; j < sideLength; j++)
            printf("%02d  ",matrix[i][j]);

        printf("\n" );
    }
    
    // determining whether the given matrix is lower matrix or upper matrix or tri triangular matrix
    int isLower = isLowerMatrix(matrix, sideLength);
    int isUpper = isUpperMatrix(matrix, sideLength);
    int isTridiagonal  = isTriDiagonalMatrix(matrix, sideLength);
    int isNull = isNullMatrix(matrix,sideLength);

    if (isNull == 1)
        printf("\n\nThe given matrix is NULL");
    else if(isLower == 1 && isUpper == 1)
        printf("\n\nThe given matrix is Tri-diagonal Matrix");
    else if (isTridiagonal == 1)
        printf("\n\nThe given matrix is a Tri-diagonal Matrix");
    else if (isLower == 1)
        printf("\n\nThe given matrix is a Lower Matrix");
    else if (isUpper == 1)
        printf("\n\nThe given matrix is a Upper Matrix");
    else
        printf("\n\nThe given matrix is neither Upper Matrix nor Lower Matrix nor Tri-diagonal matrix");

    return 0;
}