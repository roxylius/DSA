// CONVERT INFIX TO POSTFIX EXPRESSION USING STACKS
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

struct stack *sign, *postfixExp;
char *infix;

float assignPrecedence(char c);

void pushPost(char c);

char popPost();

void pushSign(char c);

char popSign();

// void display(stack *st);

int isEmpty(stack *st);

void convertInfixToPostfix();

int isSign(char c);

int main()
{
    sign = malloc(sizeof(stack));
    postfixExp = malloc(sizeof(stack));

    sign->top = -1;
    postfixExp->top = -1;

    int size;
    printf("Enter size of expression: ");
    scanf("%d", &size);
    sign->size = size;
    postfixExp->size = size;

    infix = malloc(sizeof(char) * size);
    sign->string = malloc(sizeof(char) * sign->size);
    postfixExp->string = malloc(sizeof(char) * postfixExp->size);

    printf("\nEnter the expression: ");
    scanf("%s", infix);

    // printf("\n%s",infix[]);
    // strcpy(sign->name, "sign");
    // strcpy(postfixExp->name, "postfix");
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

void pushPost(char c)
{
    if (postfixExp->top >= postfixExp->size - 1)
    {
        // printf("\nUnable to push");
    }
    else
    {
        postfixExp->string[++postfixExp->top] = c;
        // printf("\nsucessfully pushed");
        // display(postfixExp);
    }
}

void pushSign(char c)
{
    {
        if (sign->top >= sign->size - 1)
        {
            // printf("\nUnable to push");
        }
        else
        {
            sign->string[++sign->top] = c;
            // printf("\nsucessfully pushed");
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
        // display(sign);
        return c;
    }
    return '~';
}

char popPost()
{
    if (postfixExp->top == -1)
    {
        // printf("\nunable to pop");
    }
    else
    {
        // printf("\nEle successfully popped");
        char c = postfixExp->string[postfixExp->top--];
        // display(postfixExp);
        return c;
    }
    return '~'; // to detect error
}

// void display(stack *st)
// {
//     printf("\n\nthe %s stack->\n", st->name);
//     for (int i = st->top; i >= 0; i--)
//     {
//         printf("%c\n", st->string[i]);
//     }
// }

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
    for (int i = 0; infix[i] != '\0'; i++)
    {
        // printf("\n[char: %c]", infix[i]);
        if (isSign(infix[i]) == 0)
        {
            // printf("\nThe given char is an Alphabet\n");
            pushPost(infix[i]);
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
                        pushPost(pop);
                        // printf("\n[The val of int top: %d]",sign->top);
                        preceTop = assignPrecedence(sign->string[sign->top]);
                    }
                    pushSign(infix[i]);
                    // display(sign);
                }
            }
        }
    }
    if (sign->top >= 0)
    {
        // display(sign);
        // if (isEmpty(sign) != 1)
        //     printf("\nsign stack empty");
        while (isEmpty(sign) != 1)
        {
            // printf("Loop Entered!");
            char pop = popSign();
            // printf("\nThe popped ele:%c", pop);
            pushPost(pop);
        }
        // display(sign);
        // display(postfixExp);
        // printf("\nThe end if sign stack not empty the pop and add to exp");
    }
    // display(postfixExp);
    printf("\nThe postfix expression: ");
    for (int i = 0; i <= postfixExp->top; i++)
    {
        printf("%c", postfixExp->string[i]);
    }
}