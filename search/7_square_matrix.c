// let A be square matrix

#include <stdio.h>
int main()
{
    // size of square matrix
    int n;
    printf("\nEnter the no of rows and cols of matrix: ");
    scanf("%d", &n);

    // taking values for square matrix
    int array[n][n];
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter value for array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // printing the desired matrix
    printf("\nThe Given Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t    ");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }

    // A)Find number of non zero number in the square matrix

    //  // loop through all the element and check whether and also count the number of elements that are non zero
    int numberOfNonZero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] != 0)
                numberOfNonZero++;
        }
    }
    printf("\nA)Thus the Number of Non-Zero Elements in Array: %d", numberOfNonZero);

    // B)Find the the sum of elements above the leading diagonal

    //  // loop to find the sum of element above leading diagonal(top left to bottom right)
    int sumOfElements = 0;
    //  //  // here (n-1) to exclude the diagonal
    for (int i = 0; i < n - 1; i++)
    {
        //  //  // here (i+1) to exclude the diagonal
        for (int j = i + 1; j < n; j++)
        {
            sumOfElements += array[i][j];
        }
    }
    printf("\n\nB)Sum of All the Elements Above the Leading Diagonal: %d", sumOfElements);

    // C)Display the Elements below the Minor Diagonal

    //  // loop to find and print the elements below Minor diagonal (from top right to bottom left)
    printf("\n\nC)All the elements below the Minor Diagonal: \n");
    for (int i = 1; i < n; i++)
    {
        // to add space before the numbers
        for (int space = n - i; space > 0; space--)
        {
            printf("\t");
        }

        // loops and reduces the value of j(col) after every iteration thus getting all the el excluding minor diagonal
        for (int j = n - i; j < n; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // D)Find product of diagonal elements

    //  // product of Leading diagonal
    int diagonalProduct = 1;
    for (int i = 0; i < n; i++)
        diagonalProduct = diagonalProduct * array[i][i];

    //  // product of Minor Diagonal
    for (int i = 0; i < n; i++)
        diagonalProduct = diagonalProduct * array[i][n - i - 1];

    //  // removing the center element of the matrix as it is repeated twice
    if (diagonalProduct != 0)
        diagonalProduct = diagonalProduct / array[n / 2][n / 2];

    printf("\nD)Product of diagonal elements: %d", diagonalProduct);
    return 0;
}
