#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

node *create_new_node(int value)
{
    node *newNode = malloc(sizeof(node)); // alloctes the memory for a node on a heap then stores the address in a pointer
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printingLinkedList()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\b\b ");
}

int input_linked_list()
{
    int index = 0;
    printf("Enter values for linked list and enter 0 to Stop:\n");
    node *temp = head;
    while (1)
    {
        int value;
        printf("value [%d]: ", index + 1);
        scanf("%d", &value);

        if (head == NULL)
        {
            break;
        }
        else
        {
            if (index == 0)
            {
                head = create_new_node(value);
                temp = head;
                index = 1;
            }
            else
            {
                temp->next = create_new_node(value);
                temp = temp->next;
                index++;
            }
        }
    }
}

void reverse_linked_list()
{
    node *prev = NULL;
    node *cur = head;
    node *next;

    while (cur != NULL)
    {
        next = cur->next; //stores the address of next node in next

        cur->next = prev; //replacing the add of next node with prev node 

        prev = cur;    //for the next iternation the prev node will be current node

        cur = next; //for the next iteration the current node will be next node
    }
    head = prev;
}

int main()
{

    input_linked_list();
    printf("\nThe given linked list->\n" );
    printingLinkedList();
    reverse_linked_list();
    printf("\n\nThe reversed linked list->\n" );
    printingLinkedList();

    return 0;
}