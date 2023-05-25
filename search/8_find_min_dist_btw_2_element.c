// find the minimum distance between 2 number in an unsorted array
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

    // enter both the elements btw which you want to find distance
    int element1;
    int element2;
    printf("\nEnter the first Element: ");
    scanf("%d", &element1);
    printf("Enter the Second Element: ");
    scanf("%d", &element2);

    // finding indices of element1
    int element1ArrayIndex[10];
    int lengthEle1Array = 0;
    for (int i = 0; i < n; i++)
    {
        if (element1 == array[i])
        {
            element1ArrayIndex[lengthEle1Array] = i;
            lengthEle1Array++;
        }
    }

    // finding indices of element2
    int element2ArrayIndex[10];
    int lengthEle2Array = 0;
    for (int i = 0; i < n; i++)
    {
        if (element2 == array[i])
        {
            element2ArrayIndex[lengthEle2Array] = i;
            lengthEle2Array++;
        }
    }

    // finding distance between the elements
    int distances[20];
    int distanceIndex = 0;
    for (int i = 0; i < lengthEle1Array; i++)
    {
        for (int j = 0; j < lengthEle2Array; j++)
        {
            int small = element1ArrayIndex[i] < element2ArrayIndex[j] ? element1ArrayIndex[i] : element2ArrayIndex[j];
            int large = element1ArrayIndex[i] > element2ArrayIndex[j] ? element1ArrayIndex[i] : element2ArrayIndex[j];

            int distanceBetween = large - small;

            // pushing distance in the array distances
            distances[distanceIndex] = distanceBetween;
            distanceIndex++;
        }
    }

    // finding the smallest distance by finding the smallest number in array distance
    int smallestDistances = distances[0];

    for (int i = 0; i < distanceIndex; i++)
    {
        if (smallestDistances > distances[i])
        {
            smallestDistances = distances[i];
        }
    }

    // displaying the smallest distance
    printf("\nThe smallest distance between the 2 Elements: %d", smallestDistances);
    return 0;
}