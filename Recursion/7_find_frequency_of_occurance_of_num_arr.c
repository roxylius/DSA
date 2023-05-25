// find the frequency of occurances of numbers in an array
#include <stdio.h>
#include <stdlib.h>

void frequencyOfOccurances ( int *array,int len){
    //creating a copy of given array
    int *newArray = (int *)malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
        newArray[i] = array[i];
    

    // frequency of all the elements in an array
    int *freqArr = (int *)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        int num = array[i];
        int numOfOccurance = 0;
        int firstOccurance = 0;

        for (int j = 0; j < len; j++)
        {
            if (num == array[j])
            {
                numOfOccurance++;
                firstOccurance++;

                if (firstOccurance > 1)
                    array[j] = 0;

            }
        }
        freqArr[i] = numOfOccurance;
    }

    // displaying the number of occurances and the given array
    printf("\n\nThe given array = {" );
    for (int i = 0; i < len; i++)
        printf("%d, ",newArray[i]);
    printf("\b\b}" );

    
    printf("\n\nThe number of occurances of elements ->");

    for (int i = 0; i < len; i++)
    {
        if (array[i] != 0)
            printf("\n%d = %d",array[i],freqArr[i]);
    }
}


int main()
{
    // size of array
    int n;
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    // dynamically allocating the array
    int *array = (int *)malloc(n * sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }

    // find the frequency occurances of numbers in an array
    frequencyOfOccurances(array,n);

    return 0;
}