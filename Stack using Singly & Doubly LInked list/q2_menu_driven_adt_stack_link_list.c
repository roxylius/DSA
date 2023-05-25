#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *top = NULL;

node *create_new_node(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void push()
{
    int val;
    printf("\nEnter the val to push: ");
    scanf("%d", &val);
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nSTACK OVERFLOW! Unable to push!");
        free(temp);
    }
    else
    {
        node *cur = create_new_node(val);
        cur->next = top;
        top = cur;
        printf("The element was successfully pushed!");
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\nSTACK UNDERFLOW! Unable to pop!");
    }
    else
    {
        node *cur = top;
        top = top->next;
        free(cur);
        printf("\nTop element popped!");
    }
}

void isEmpty()
{
    if (top == NULL)
        printf("\nThe stack is EMPTY!");
    else
        printf("\nThe stack is NOT EMPTY!");
}

void display()
{
    if (top == NULL)
        printf("\nThe given STACK is EMPTY!");
    else
    {
        node *temp = top;
        printf("\nThe given stack->\n");
        while (temp != NULL)
        {
            printf("%02d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
restart:
    printf("\n\nEnter 1 for push\n");
    printf("Enter 2 for pop\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 to check if stack is empty\n");
    printf("Enter 5 to exit");
    printf("\n\nEnter ur choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        push();
        goto restart;

    case 2:
        pop();
        goto restart;

    case 3:
        display();
        goto restart;

    case 4:
        isEmpty();
        goto restart;

    case 5:
        break;

    default:
        printf("\nWRONG NUMBER ENTERED!");
        goto restart;
    }

    return 0;
}