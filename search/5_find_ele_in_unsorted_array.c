// find an element between 2 elements in an unsorted array
#include <stdio.h>
int main()
{
    // size of array
    int n;
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    // taking values for array
    int array[n];
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    // the 2 elements between which
    int firstElement, lastElement;
    printf("\nTo look for the elements between 2 numbers in an array");
    printf("\nEnter the 1st number : ");
    scanf("%d", &firstElement);
    printf("Enter the 2nd number : ");
    scanf("%d", &lastElement);

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

    // finding the elements between 2 elements in the array

    // sorting the two number
    int small = firstElement < lastElement ? firstElement : lastElement;
    int big = firstElement < lastElement ? lastElement : firstElement;

    // finding index of both the element element
    int indexFirstElement;
    int indexLastElement;
    for (int i = 0; i < n; i++)
    {
        if (small == array[i])
            indexFirstElement = i;

        else if (big == array[i])
            indexLastElement = i;
    }

    // finding and printing elements between the two indices in the array
    int differenceBetweenIndex = indexLastElement - indexFirstElement;
    if (differenceBetweenIndex != 0 && differenceBetweenIndex != 1)
    {
        printf("\nThe elements between the 2 numbers = ");
        for (int i = indexFirstElement + 1; i < indexLastElement; i++)
        {
            printf("%d, ", array[i]);
        }
        printf("\b\b ");
    }
    else
    {
        printf("\nSorry, There are no numbers between the 2 given numbers in the array");
    }

    return 0;
}