// print all the permutation of a given string using pointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *character1, char *character2)
{
    char temp = *character1;
    *character1 = *character2;
    *character2 = temp;
}

void permutateString(char *string, int currentIndex)
{
    if (currentIndex == strlen(string))
    {
        printf("%s\n", string);
    }

    for (int i = currentIndex; i < strlen(string); i++)
    {
        swap(string + i, string + currentIndex);
        permutateString(string, currentIndex + 1);
        swap(string + i, string + currentIndex);
    }
}

int main()
{
    char *string = (char *)malloc(20 * sizeof(char));
    printf("Enter the String: ");
    scanf("%s", string);

    // printing permutation of string
    printf("\nAll the permutation of the string '%s':\n");
    permutateString(string, 0);
    return 0;
}