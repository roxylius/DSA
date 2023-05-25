#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *link;
} node;

node *head = NULL;

node *create_new_node(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = val;
    newNode->link = head;

    return newNode;
}

void takingVal()
{
    int val;
    node *temp = head;
    int i = 0;
    printf("\nEnter the val for link list and enter 0 to stop->\n");
    while (1)
    {
        printf("val[%d]: ", ++i);
        scanf("%d", &val);
        if (val == 0)
        {
            temp->link = head;
            break;
        }
        else
        {
            if (i == 1)
            {
                head = create_new_node(val);
                temp = head;
            }
            else
            {
                temp->link = create_new_node(val);
                temp = temp->link;
            }
        }
    }
}

void display_Cir_list()
{
    node *temp = head;

    do
    {
        printf("%d - ", temp->value);
        temp = temp->link;

    } while (temp != head);

    printf("\b\b ");
}

// b
void check_if_empty()
{
    if (head == NULL)
        printf("\n\nThe given linked list is empty!");
    else
        printf("\n\nThe given linked list is not empty!");
}

void traverse_link_list()
{
    node *temp = head;
    int i, idxOfList = 0;
    printf("\nEnter the index of node to traverse: ");
    scanf("%d", &i);

    printf("\nThe given linked list: ");
    display_Cir_list();

    printf("\n\nThe node at index %d: ", i);
    do
    {
        if ((idxOfList++ + 1) == i) // as when the idx is 0 it prints the 1st node to print val of nth node i == (idx+1)
            printf("%d", temp->value);

        temp = temp->link;

    } while (temp != head);
}

void delete_at_pos()
{
    printf("\n\nThe given linked list: ");
    display_Cir_list();

    int pos, index = 0;
    printf("\n\nEnter the postion to delete: ");
    scanf("%d", &pos);
    node *prev = NULL;
    node *cur = head;
    node *next = head->link;
    do
    {
        index++;
        if (index == pos)
        {
            prev->link = next;
            free(cur);
            break;
        }
        prev = cur;
        cur = next;
        next = next->link;
    } while (cur != head);

    printf("\nThe given linked list: ");
    display_Cir_list();
}

void insert_at_pos()
{
    printf("\n\nThe given linked list: ");
    display_Cir_list();

    int pos, num, index = 0;
    printf("\n\nEnter the postion to insert: ");
    scanf("%d", &pos);

    printf("Enter the val of inserted node: ");
    scanf("%d", &num);
    node *prev = NULL;
    node *cur = head;
    node *newNode = create_new_node(num);
    if (pos == 1)
    {
        do
        {
            prev = cur;
            cur = cur->link;
        } while (cur != head);

        newNode->link = cur;
        head = newNode;
        prev->link = head;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            prev = cur;
            cur = cur->link;
        }

        prev->link = newNode;
        newNode->link = cur;
    }

    printf("\nThe linked list after insertion: ");
    display_Cir_list();
}

void delete_node_for_key()
{
    printf("\n\nThe given linked list: ");
    display_Cir_list();

    int key;
    printf("\n\nEnter the val of key of node to delete: ");
    scanf("%d", &key);
    node *prev = NULL;
    node *cur = head;
    node *next = cur->link;

    do
    {
        if (cur->value == key)
        {
            prev->link = next;
            free(cur);
            break;
        }

        prev = cur;
        cur = next;
        next = next->link;
    } while (cur != head);

    printf("\nThe linked list after deletion: ");
    display_Cir_list();
}

void count_total_nodes()
{
    node *temp = head;
    int i = 0;
    do
    {
        i++;
        temp = temp->link;
    } while (temp != head);

    printf("\n\nThe total num of nodes: %d", i);
}

void search_for_ele()
{
    printf("\nThe given linked list: ");
    display_Cir_list();

    int query, i = 0;
    printf("\nEnter val of node to search: ");
    scanf("%d", &query);

    node *temp = head;
    do
    {
        i++;
        if (temp->value == query)
            break;

        temp = temp->link;
    } while (temp != head);

    printf("\nThe index of node with val %d: %d", query, i);
}

int main()
{
    takingVal();
    int choiceNum, count;
    printf("\n\nEnter 1 for Traversal of the list\n");
    printf("Enter 2 to check if list is empty!\n");
    printf("Enter 3 to Insert node at any pos\n");
    printf("Enter 4 to Delete node at any pos\n");
    printf("Enter 5 to delete node for a given key\n");
    printf("Enter 6 to count the total number of nodes\n");
    printf("Enter 7 to Search for an element in linked list\n");
    printf("Enter your Choice: ");
    scanf("%d", &choiceNum);

    switch (choiceNum)
    {
    case 1:
        traverse_link_list();
        break;

    case 2:
        check_if_empty();
        break;

    case 3:
        insert_at_pos();
        break;

    case 4:
        delete_at_pos();
        break;

    case 5:
        delete_node_for_key();
        break;

    case 6:
        count_total_nodes();
        break;

    case 7:
        search_for_ele();
        break;

    default:
        printf("Error wrong number Entered!!!");
        break;
    }
    return 0;
}