// find the largest number in an array also find the number of occurences of the number using single loop
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

    // finding largest no and its occurance using single loop
    int largest = array[0];
    int numOfLargest = 0;
    int isFoundLargest = 0;
    for (int i = 0; i < n; i++)
    {
        if (isFoundLargest == 0)
        {
            for (int j = 0; j < n; j++)
            {
                isFoundLargest++;
                if (largest < array[j])
                    largest = array[j];
            }
        }

        if (largest == array[i])
            numOfLargest++;
    }

    printf("\n\nThe Largest number in the Array: %d", largest);
    printf("\nThe number of Occurance Of %d in Array: %d", largest, numOfLargest);

    return 0;
}