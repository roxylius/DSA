// reverse the contents of an array of size n
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

    //printing given array
    printf("\nThe given array = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}\n");

    // reversing the elements of an array
    for (int i = 0; i < n / 2; i++)
    {
        int temporary = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temporary;
    }

    // printing the array
    printf("\nThe reversed array = {");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b}");

    return 0;
}