// store name, gender, designation, department and basic salary of n number of employees
#include <stdio.h>

struct employeeInfo
{
    char name[20];
    char designation[15];
    char department[10];
    int gender;
    int salary;
    float grossSalary;
};

typedef struct employeeInfo employeeInfo;

void grossSalary(employeeInfo *employees)
{
    int salary = employees->salary;
    float da = salary * (75 / 100.0);
    float hra = salary * (25 / 100.0);

    employees->grossSalary = salary + da + hra;
}

int main()
{
    // no of employees
    int employeesSize;
    printf("Enter the number of employees: ");
    scanf("%d", &employeesSize);

    // creating an array of employees
    struct employeeInfo employees[employeesSize];

    // loop to store info about diff employees
    printf("\nEnter the details of employees =>\n");
    for (int i = 0; i < employeesSize; i++)
    {
        printf("\nEmployee %d =>\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", &employees[i].name);
        printf("Gender: ");
        scanf("%s",&employees[i].gender);
        printf("Designation: ");
        scanf("%s",&employees[i].designation);
        printf("Department: ");
        scanf("%s",&employees[i].department);
        printf("Salary: ");
        scanf("%d", &employees[i].salary);

        // gross salary of all employees
        grossSalary(employees + i);
    }

    // printing the gross pay of all employees
        printf("\n\nGross Salaries-->");
    for (int i = 0; i < employeesSize; i++)
    {
        printf("\n%d)%s",i+1,employees[i].name);
        printf("\n  Gross Salary: %0.2f\n",employees[i].grossSalary);
    }
    
    return 0;
}