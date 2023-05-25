// adding two complex numbers by passing structures to a function
#include <stdio.h>

typedef struct complexNum
{
    int realNum;
    char operator;
    int imaginaryNum;
    char imaginarySymbol;
} complex;

void addComplexNumbers(complex *nums)
{
    int realNumSum = nums[0].realNum + nums[1].realNum;
    int imaginaryNumOperate = nums[0].imaginaryNum + nums[1].imaginaryNum;
    printf("\nThe sum of the two Complex Numbers: %d + (%di)",realNumSum,imaginaryNumOperate);
}

int main()
{
    //array of 2 complex nums
    complex nums[2];

    //taking values of the complex numbers to add
    printf("Enter the Complex numbers[Format:a +bi] to Add -->\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d %d %c", &nums[i].realNum, & nums[i].imaginaryNum, &nums[i].imaginarySymbol);
    }

    //adding and printing the sum of two complex numbers
    addComplexNumbers(nums);

    return 0;
}