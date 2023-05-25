// replace every element the multiplication of the previous and next el in array of size n
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

    // replacing every element with multiplication of element before and after it
    
    //for 1st ele
    array[0] *= array[1];

    //for rest ele
    for (int i = 1; i < n - 1; i++)
    {
        array[i] = array[i + 1] * array[i - 1];
    }

    //for last ele
    array[n-1] *= array[n - 2];

    // printing the array
    printf("\nThe Desired Array = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}");

    return 0;
}