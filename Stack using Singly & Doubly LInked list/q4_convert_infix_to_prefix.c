// wap to convert infix expression to prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *string;
    int top;
    int size;
    // char name[10]; // debug
} stack;

struct stack *sign, *prefixExp;
char *infix;

float assignPrecedence(char c);

void pushPrefix(char c);

char popPrefix();

void pushSign(char c);

char popSign();

void display(stack *st);

int isEmpty(stack *st);

void convertInfixToPostfix();

int isSign(char c);

int sizeOfInfix();

int main()
{
    sign = malloc(sizeof(stack));
    prefixExp = malloc(sizeof(stack));

    sign->top = -1;
    prefixExp->top = -1;

    int size;
    printf("Enter size of expression: ");
    scanf("%d", &size);
    sign->size = size;
    prefixExp->size = size;

    infix = malloc(sizeof(char) * size);
    sign->string = malloc(sizeof(char) * sign->size);
    prefixExp->string = malloc(sizeof(char) * prefixExp->size);

    printf("\nEnter the expression: ");
    scanf("%s", infix);

    // printf("\n%s",infix[]);
    // strcpy(sign->name, "sign");
    // strcpy(prefixExp->name, "prefix");
    convertInfixToPostfix();
    return 0;
}

float assignPrecedence(char c)
{
    switch (c)
    {
    case '-':
    case '+':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
        return -1;
    }
}

void pushPrefix(char c)
{
    if (prefixExp->top >= prefixExp->size - 1)
    {
        // printf("\nUnable to push");
    }
    else
    {
        prefixExp->string[++prefixExp->top] = c;
        // printf("\nsucessfully pushed");
        // printf("\npushed ele: [[%c]]", c);
        // display(prefixExp);
    }
}

void pushSign(char c)
{
    {
        if (sign->top > sign->size - 1)
        {
            // printf("\nUnable to push");
        }
        else
        {
            sign->string[++sign->top] = c;
            // printf("\nsucessfully pushed");
            // printf("\npushed ele: [[%c]]", c);
            // display(sign);
        }
    }
}

char popSign()
{
    if (sign->top == -1)
    {
        // printf("\nunable to pop");
    }
    else
    {
        // printf("\nEle successfully pushed");
        char c = sign->string[sign->top--];
        // printf("\npopped ele: [[%c]]",c);
        // display(sign);
        return c;
    }
    return '\0';
}

char popPrefix()
{
    if (prefixExp->top == -1)
    {
        // printf("\nunable to pop");
    }
    else
    {
        // printf("\nEle successfully popped");
        char c = prefixExp->string[prefixExp->top--];
        // printf("\npopped ele: [[%c]]",c);
        // display(prefixExp);
        return c;
    }
    return '\0';
}

// void display(stack *st)
// {
//     printf("\n\nthe %s stack->\n", st->name);
//     for (int i = st->top; i >= 0; i--)
//     {
//         printf("%c\n", st->string[i]);
//     }
// }

int sizeOfInfix()
{
    int i;
    for (i = 0; infix[i] != '\0'; i++)
        ;
    return i - 1;
}

int isEmpty(stack *st)
{
    if (st->top == -1)
    {
        // printf("\nThe given stack is empty");
        return 1;
    }
    else
    {
        // printf("\nThe given stack is not empty!");
        return 0;
    }
}

int isSign(char c)
{
    switch (c)
    {
    case '-':
    case '+':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}

void convertInfixToPostfix()
{
    // printf("[[%c]]",infix[sizeOfInfix()-1]);
    for (int i = sizeOfInfix(); i >= 0; i--)
    {
        // printf("\n[char: %c]", infix[i]);
        if (isSign(infix[i]) == 0)
        {
            // printf("\nThe given char is an Alphabet\n");
            pushPrefix(infix[i]);
        }
        else
        {
            // printf("\nThe given char is sign\n");
            if (isEmpty(sign))
            {
                pushSign(infix[i]);
                // printf("\nThe given stack empty pushed!\n");
            }
            else
            {
                float preceTop = assignPrecedence(sign->string[sign->top]);
                float preceToAdd = assignPrecedence(infix[i]);
                if (preceToAdd > preceTop)
                {
                    // printf("\n\nThe precedence of the element to add is greater than topmost element");
                    pushSign(infix[i]);
                }
                else
                {
                    // printf("\n\nThe precedence of the ele to add is lower than the topmost ele");
                    while (preceToAdd <= preceTop)
                    {
                        char pop = popSign();
                        // printf("\nThe popped ele:%c", pop);
                        pushPrefix(pop);
                        // printf("\n[The val of int top: %d]",sign->top);
                        preceTop = assignPrecedence(sign->string[sign->top]);
                    }
                    // printf("this: [[%c]]", infix[i]);
                    pushSign(infix[i]);
                    // display(sign);
                }
            }
        }
    }
    if (sign->top >= 0)
    {
        // display(sign);
        if (isEmpty(sign) == 1)
            // printf("\nsign stack empty");
        while (isEmpty(sign) != 1)
        {
            // printf("Loop Entered!");
            char pop = popSign();
            // printf("\nThe popped ele:%c", pop);
            pushPrefix(pop);
        }
        // display(sign);
        // printf("\nThe end if sign stack not empty the pop and add to exp");
    }
    printf("\nThe given prefix stack: ");
    for (int i = sizeOfInfix(); i >= 0; i--)
        printf("%c", prefixExp->string[i]);
}