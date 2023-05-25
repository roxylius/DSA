// using function add two polynomial
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int order;
    int *coefficients;
    int x;
} polynomial;

// fn to evalute polynomial for x
int evalutePolynomial(polynomial var);

void takingValues(polynomial *var);

void printingPolynomial(polynomial var);

int main()
{
    // creating 2 polynomials
    polynomial polynomial1;
    polynomial polynomial2;

    // taking values of polynomials
    takingValues(&polynomial1);
    takingValues(&polynomial2);

    // taking value of x
    int x;
    printf("\nEnter the Value of x: ");
    scanf("%d", &x);

    // entering val of x in polynomial
    polynomial1.x = x;
    polynomial2.x = x;

    // evaluting the given polynomial for x
    int valueOfPolynomial1 = evalutePolynomial(polynomial1);
    int valueOfPolynomial2 = evalutePolynomial(polynomial2);

    // adding both the polynomial
    int sumOfPolynomial = valueOfPolynomial1 + valueOfPolynomial2;

    // printing the sum
    printf("\nf(x) = h(x) + g(x) ->\n");
    printf("\nf(%d) = ", x);
    printingPolynomial(polynomial1);
    printf(" + ");
    printingPolynomial(polynomial2);
    printf(" = %d", sumOfPolynomial);

    return 0;
}

// fn to evalute polynomial for x
int evalutePolynomial(polynomial var){
    int evalute = 0;
    for (int i = 0; i <= var.order; i++)
    {
        // calculting the x^(3) , x^(2) and so on by substituting value of x
        int variableWithValOfX = 1;
        for (int j = 0; j < i; j++)
        {
            variableWithValOfX *= var.x;
        }

        // multipling the coeff with the respective variable
        evalute += (var.coefficients[var.order - i]) * variableWithValOfX;
    }
    return evalute;
}

void takingValues(polynomial *var){
    // taking the order of polynomial
    printf("Enter The Order of Polynomial[p(x)]: ");
    scanf("%d", &var->order);

    // creating a dynamic array of coefficients
    var->coefficients = (int *)malloc((var->order + 1) * sizeof(int));

    // taking the values of coefficients
    printf("\nEnter the Coefficient of Polynomial ->\n");
    int order = var->order;
    for (int i = 0; i <= order; i++)
    {
        int coeff = order - i;
        printf("Coeff for x^(%d): ", coeff);
        scanf("%d", &var->coefficients[i]);
    }
    printf("\n");
}

void printingPolynomial(polynomial var){
    // printing the polynomial
    printf("[");
    for (int i = var.order; i > 0; i--)
    {
        printf("%dx^(%d) + ", var.coefficients[var.order - i], i);
    }
    printf("%d", var.coefficients[var.order]);
    printf("]");
}