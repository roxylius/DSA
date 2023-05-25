// read and display a one dimensional array, calculate sum of all elements of dynamically allocated array
#include <stdio.h>
#include <stdlib.h>

int sumOfAllElementOfArr(int array[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += array[i];

    return sum;
}

int main()
{
    // taking the length of array
    int lengthOfArr;
    printf("Enter length of Array : ");
    scanf("%d", &lengthOfArr);

    // creating a dynamically allocated array
    int *arr = (int *)malloc(lengthOfArr * sizeof(int));

    // taking the values of the array
    printf("\n");
    for (int i = 0; i < lengthOfArr; i++)
    {
        printf("enter any value for (%02d) = ", (i + 1));
        scanf("%d", &arr[i]);
    }

    // displaying the given array
    printf("\nArray you entered --> {");
    for (int i = 0; i < lengthOfArr; i++)
    {
        printf("%02d,  ", arr[i]);
    }
    printf("\b\b\b}");

    // adding all the elements in array
    int sumOfArray = sumOfAllElementOfArr(arr, lengthOfArr);

    printf("\n\nSum of All the Elements in The Array: %d", sumOfArray);
    return 0;
}
