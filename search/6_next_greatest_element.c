// find the next greatest element to every element in the array according to both index succeding and its value
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

    // finding and printing the elements greater than and succeeding the element
    int greaterThanElement;
    int isGreaterThan;
    printf("\nElement\t\tNGE\n");
    for (int i = 0; i < n; i++)
    {
        isGreaterThan = 0;
        greaterThanElement = array[i];

        // checks and finds  if there are any elements in the array greater than the given element
        for (int j = i; j < n; j++)
        {
            if (greaterThanElement < array[j])
            {
                greaterThanElement = array[j];
                isGreaterThan++;
                break;
            }
        }

        // prints the greater than element if one else displays -1
        if (isGreaterThan != 0)
            printf("%d\t\t%d\n", array[i], greaterThanElement);
        else
            printf("%d\t\t%d\n", array[i], -1);
    }

    return 0;
}