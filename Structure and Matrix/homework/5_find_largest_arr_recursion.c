//find the largest element in the array using recursion
#include<stdio.h>
#include<stdlib.h>

int findingTheLargestUsingRecursion(int *array,int largest,int len){
    static int i;
    if (i == len)
        return largest;
    
    if (largest < array[i])
        largest = array[i];

    i++;

    findingTheLargestUsingRecursion(array,largest,len);
      

}

int main()
{
    //taking the size of array
    int n;
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    // dyanmically allocatinh the array
    int *array = (int *)malloc(n * sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }

    //finding the largest element using recursion
    int largest = array[0];
    int largestNum = findingTheLargestUsingRecursion(array,largest,n);

    // displaying the given array
    printf("\n\nThe given array = {" );
    for (int i = 0; i < n; i++)
        printf("%d, ",array[i]);
    printf("\b\b}" );

    //displaying the largest element
    printf("\n\nThe largest number in Arr : %d",largestNum);


    return 0;
} 