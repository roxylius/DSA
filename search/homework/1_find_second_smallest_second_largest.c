// find out the second smallest and second largest element stored in an array
#include <stdio.h>
int main()
{
    int n;
    int secondSmallest;
    int secondLargest;

    // size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    // taking values for array
    int array[n];
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    // sorting using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }

    printf("\nThe 2nd Smallest Element: %d", array[1]);
    printf("\nThe 2nd Largest Element: %d", array[n - 2]);
    return 0;
}