// find the kth largest and kth smallest element stored in an dynamic array
#include <stdio.h>
#include <stdlib.h>
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

    // taking the value of k
    int k;
    printf("\n\nEnter the value of k to find kth largest and smallest el: ");
    scanf("%d", &k);

    // finding the kth smallest element and kth largest element
    printf("\n\nThe %d Smallest element in Array = %d", k, array[k - 1]);
    printf("\nThe %d Largest element in Array = %d", k, array[(n - 1) - (k - 1)]);

    return 0;
}