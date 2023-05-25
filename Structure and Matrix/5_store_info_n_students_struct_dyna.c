// store info of n students using structres and dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

struct studentInfo
{
    char name[20];
    int roll;
    int age;
    int class;
};

int main()
{
    // no of students
    int studentSize;
    printf("Enter the number of students: ");
    scanf("%d", &studentSize);

    // creating an dynamic array of students
    struct studentInfo *students = (struct studentInfo*)malloc(studentSize*sizeof(struct studentInfo));

    // loop to store info about diff students
    printf("\nEnter the Details of students -->");
    for (int i = 0; i < studentSize; i++)
    {
        printf("\nstudent %02d ->\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", &students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("Age: ");
        scanf("%d",&students[i].age);
        printf("Class: ");
        scanf("%d",&students[i].class);
    }

    // displaying info about students
    printf("\n\nDetails of students -->");
    for (int i = 0; i < studentSize; i++)
    {
        printf("\nstudent %02d ->", i + 1);
        printf("\nName: %s",students[i].name);
        printf("\nRoll No: %d", students[i].roll);
        printf("\nAge: %d", students[i].age);
        printf("\nClass: %d\n", students[i].class);
    }

    return 0;
}

