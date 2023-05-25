// create and display all the nodes of doubly linked list of n nodes
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

node *HEAD = NULL;

node *create_new_node(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void create_doubly_linked_list()
{
    int val, i = 0;
    node *temp = NULL;
    printf("Enter val for linked list and enter 0 to stop: \n");
    while (1)
    {
        printf("val[%d]: ", i++);
        scanf("%d", &val);
        if (val == 0)
            break;
        if (HEAD == NULL && val != 0)
        {
            HEAD = create_new_node(val);
            temp = HEAD;
        }
        else if (val != 0)
        {
            temp->next = create_new_node(val);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }
}

void display_list()
{
    node *temp = HEAD;
    if(temp == NULL)
        return;
    printf("\n\nForward: ");
    while (temp->next != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("%d - ", temp->data);
    printf("\b\b ");

    printf("\nbackward: ");
    while (temp->prev != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->prev;
    }
    printf("%d - ", temp->data);
    printf("\b\b ");
}

int main()
{
    create_doubly_linked_list();
    display_list();
    return 0;
}