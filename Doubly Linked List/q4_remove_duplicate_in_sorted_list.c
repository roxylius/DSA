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

void remove_duplicates()
{
    node *temp = head;
    while (temp != NULL)
    {
        int val = temp->data;
        node *cur = temp->next;
        while (cur != NULL)
        {
            if (cur->data == val)
            {
                if (cur->next == NULL)
                {
                    cur->prev->next = NULL;
                    free(cur);
                    break;
                }
                node *temp = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            cur = cur->next;
        }
        temp = temp->next;
    }

    printf("\n\nThe new linked list After removing duplicates-->");
    display_list();
}

int main()
{
    create_doubly_linked_list();
    display_list();
    remove_duplicates();
    return 0;
}