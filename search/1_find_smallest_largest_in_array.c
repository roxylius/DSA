// find out the smallest and largest number stored in an array of size n
#include <stdio.h>
int main()
{
    int n;
    int smallest;
    int largest;

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

    // length of array
    // int arrayLength = sizeof(array) / sizeof(array[0]);

    // to find the smallest element in an array
    smallest = array[0];
    for (int i = 0; i < n; i++)
    {
        if (smallest > array[i])
            smallest = array[i];
    }

    // to find the largest element in an array
    largest = array[0];
    for (int i = 0; i < n; i++)
    {
        if (largest < array[i])
            largest = array[i];
    }

    printf("\n\nThus the Smallest Element in the Array = %d", smallest);
    printf("\nThus the Largest Element in the Array = %d", largest);

    return 0;
}