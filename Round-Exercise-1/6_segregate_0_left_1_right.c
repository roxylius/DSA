// segregate the 0s on the left and 1s on the right by only transversing through array once
#include <stdio.h>
#include <stdlib.h>

void swap(int *value1, int *value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int main()
{
    // size of array
    int n;
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    // taking values for array
    int *array = (int *)malloc(n * sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    // printing the array
    printf("\n\nThe given array: {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}");

    // transvering the once and segregating 1s and 0s
    int indexOfZeroes = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            swap(array + indexOfZeroes, array + i);
            indexOfZeroes++;
        }
    }

    // printing the rearranged array
    printf("\n\nThe rearranged array: {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}");

    return 0;
}