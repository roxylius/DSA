// evalute a given polynomial equation take order of polynomial , coefficient and value of x will be user input
#include <stdio.h>
#include <stdlib.h>

// fn to evalute polynomial for x
int evalutePolynomial(int *coefficients, int order, int x)
{
    int evalute = 0;
    for (int i = 0; i <= order; i++)
    {
        // calculting the x^(3) , x^(2) and so on by substituting value of x
        int variableWithValOfX = 1;
        for (int j = 0; j < i; j++)
        {
            variableWithValOfX *= x;
        }

        // multipling the coeff with the respective variable
        evalute += (coefficients[order - i]) * variableWithValOfX;
    }
    return evalute;
}

int main()
{
    int order, x;

    // taking the order of polynomial
    printf("Enter The Order of Polynomial[p(x)]: ");
    scanf("%d", &order);

    // creating a dynamic array of coefficients
    int *coefficient = (int *)malloc((order + 1) * sizeof(int));

    // taking the values of coefficients
    printf("\nEnter the Coefficient of Polynomial ->\n");
    for (int i = 0, coeff = order; i <= order; i++, coeff--)
    {
        printf("Coeff for x^(%d): ", coeff);
        scanf("%d", &coefficient[i]);
    }

    // taking the value of x of the polynomial
    printf("\nEnter the Value of x for the Polynomial p(x): ");
    scanf("%d", &x);

    // evaluting the given polynomial for x
    int valueOfPolynomial = evalutePolynomial(coefficient, order, x);

    // printing the polynomial
    printf("\n\nValue of the Polynomial ->");
    printf("\np(%d) = ", x);
    for (int i = order; i > 0; i--)
    {
        printf("%dx^(%d) + ", coefficient[order - i], i);
    }
    printf("%d", coefficient[order]);
    printf(" = %d", valueOfPolynomial);

    return 0;
}