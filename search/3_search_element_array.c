// search an element in array of n numbers
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

    // the element user wants to search
    int query;
    printf("\nEnter the element you want to search in the array: ");
    scanf("%d", &query);

    // searching the element in the array
    int isElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (query == array[i])
        {
            printf("\nThe element: %d is on index: [%d]", query, i);
            isElement = 1;
        }
    }

    // when the element is not found
    if (isElement == 0)
    {
        printf("Error: The element : %d is not in the given array", query);
    }

    return 0;
}