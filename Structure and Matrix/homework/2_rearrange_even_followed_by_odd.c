// arrange the elements of an array such that all even numbers are followed by odd 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // size of array
    int n;
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    // taking values for array
    int *array = (int *)malloc(n*sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    // sorting all even followed by odd 
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j + 1] % 2 == 0)
            {
                // exchanging values
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }

    // printing the array
    printf("\nThe sorted array = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}");

    return 0;
}