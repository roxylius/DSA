#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

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
        if (head == NULL && val != 0)
        {
            head = create_new_node(val);
            temp = head;
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
    node *temp = head;
    if (temp == NULL)
        return;
    printf("\nForward: ");
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

void reverse_list()
{
    node *cur = head;
    node *prev = NULL;
    node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    head = prev;
    
    cur = head;
    prev = NULL;
    while (cur != NULL)
    {
        cur->prev = prev;
        prev = cur;
        cur = cur->next;
    }
    
}

int main()
{
    create_doubly_linked_list();
    printf("\n\nThe given linked list: " );
    display_list();
    reverse_list();
    printf("\n\nThe reversed doubly linked list: " );
    display_list();
    return 0;
}