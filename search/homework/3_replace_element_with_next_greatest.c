// replace every element in an array with the next greatest element present in the array
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

        // replacing element with the next greatest element
        if (isGreaterThan != 0)
            array[i] = greaterThanElement;
        else
            array[i] = array[i];
    }

    // printing disired array
    printf("\nThe desired elements with all the elements replace with NGE: {");
    for (int i = 0; i < n; i++)
    {
        printf("%d,  ", array[i]);
    }
    printf("\b\b\b}");

    return 0;
}