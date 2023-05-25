#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *link;
};

typedef struct node node;

node *head;

node *create_new_node(int value);

void printingLinkedList();

void check_linked_list_is_empty();

void traversing_list();

void insert_node_at_beginning();

void insert_node_at_end();

void insert_node_at_position();

void delete_node_at_beginning();

void delete_node_at_end();

void delete_node_at_position();

void count_num_of_node();

void search_for_ele();

void insert_node_beginning_end_any();

void delete_node_beginning_end_any();

void delete_node_with_key();

void input_linked_list();

int main()
{
    input_linked_list();
    int choiceNum;
    printf("\n\nEnter 1 for Traversal of the list\n");
    printf("Enter 2 to Insert a node at the certain position(beginning,end,any)\n");
    printf("Enter 3 to Delete a node at the certain position(beginning,end,any)\n");
    printf("Enter 4 to Delete a node for given key\n");
    printf("Enter 5 to Count the total number of nodes\n");
    printf("Enter 6 to Search for an element in linked list\n");
    printf("Enter your Choice: ");
    scanf("%d", &choiceNum);

    switch (choiceNum)
    {
    case 1:
        traversing_list();
        break;

    case 2:
        insert_node_beginning_end_any();
        break;

    case 3:
        delete_node_beginning_end_any();
        break;

    case 4:
        delete_node_with_key();
        break;

    case 5:
        count_num_of_node();
        break;

    case 6:
        search_for_ele();
        break;

    default:
        printf("\n\nError wrong number Entered!");
        break;
    }

    return 0;
}

void input_linked_list()
{
    int count = 0;
    int value;
    printf("Enter values in linked list and 0 to Stop: \n");
    node *temp;
    while (1)
    {
        printf("value [%d]: ", count + 1);
        scanf("%d", &value);
        if (value == 0)
        {
            // temp->link = NULL;
            break;
        }
        else
        {
            if (count == 0)
            {
                head = create_new_node(value);
                count = 1;
                temp = head;
            }
            else
            {
                // node *newNode = create_new_node(value);
                temp->link = create_new_node(value);
                temp = temp->link;
                count++;
            }
        }
    }
}

node *create_new_node(int value)
{
    node *newNode = malloc(sizeof(node)); // alloctes the memory for a node on a heap then stores the address in a pointer
    newNode->value = value;
    newNode->link = NULL;
    return newNode;
}

void printingLinkedList()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->link;
    }
    printf("\b\b ");
}

void check_linked_list_is_empty()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    if (head == NULL)
        printf("\n\nThe linked list is EMPTY!");
    else
        printf("\n\nThe linked list in NOT EMPTY!");
}

void traversing_list()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    int position;
    printf("\n\nEnter the position to traverse in linked list: ");
    scanf("%d", &position);
    node *temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->link;
    }
    printf("\nThe node at %d position: %d", position, temp->value);
}

void insert_node_at_beginning()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    int value;
    printf("\n\nEnter the value to be Inserted in the beginning: ");
    scanf("%d", &value);

    // creates a new node and storing in the values
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->link = NULL;

    if (head == NULL) // if the list list is empty
    {
        head = newNode;
    }
    else
    {
        // create a temporary node that points to 1st element of linked list like head
        node *temp = head;

        // head points to the newNode to insert the new node at beginning
        head = newNode;

        // new node link now points to 1st node i.e. stores the address of 1st element of linked list
        newNode->link = temp;
    }
    printf("\nThe new linked list: ");
    printingLinkedList();
}

void insert_node_at_end()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    int value;
    printf("\n\nEnter the value to be Inserted in the end: ");
    scanf("%d", &value);

    // creating of new node and storing the values
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->link = NULL;

    node *temp = head; // creates a new struct node pointer that also points to same thing that head is pointing to

    if (temp == NULL) // if the linked list is NULL
    {
        head = newNode; // head points to the newNode as it is 1st element when l list is empty
    }
    else // when the linked list is not NULL
    {
        while (temp->link != NULL)
        {
            temp = temp->link; // loops till the last element has NULL in its link/next
        }
        temp->link = newNode; // stores the new node at the link/next of the last node
    }
    printf("\nThe new linked list: ");
    printingLinkedList();
}

void insert_node_at_position()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();

    int value, position;
    printf("\n\nEnter the value to Inserted: ");
    scanf("%d", &value);
    printf("And position: ");
    scanf("%d", &position);

    // create a new node and stores value in it
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->link = NULL;

    // create a temp node pointing to 1st ele of LL
    node *temp = head;

    if (head == NULL)
        printf("\nThe linked list is Empty!");
    else if (position == 1)
    {
        newNode->link = head;
        head = newNode;
    }
    else
    {
        // loops and stops at a position before where node has to added so we can change the link of the previous node
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->link;
        }

        // storing the address of the link node in the link of the newnode
        newNode->link = temp->link;

        // storing the address of newNode in the previous element
        temp->link = newNode;
    }
    printf("\nThe new linked list: ");
    printingLinkedList();
}

void delete_node_at_beginning()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    node *temp = head;

    if (head == NULL)
    {
        printf("\n\nThe given linked list is NULL!");
    }
    else
    {
        temp = head->link;
        free(head);
        head = temp;
    }
    printf("\n\nThe new linked list: ");
    printingLinkedList();
}

void delete_node_at_end()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    node *temp = head;

    if (head == NULL)
        printf("The given linked list is Empty!");
    else
    {
        // loop only runs when the link of the node link to the node is empty
        // basically to get last second node
        while (temp->link->link != 0)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
    printf("\n\nThe new linked list: ");
    printingLinkedList();
}

void delete_node_at_position()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();

    int position;
    printf("\n\nEnter the position to delete the node: ");
    scanf("%d", &position);

    printf("\nThe given linked list: ");
    printingLinkedList();

    node *temp = head;
    if (head == NULL)
    {
        printf("The given linked list is NULL!");
    }
    else if (position == 1)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->link;
        }
        node *deleted = temp->link;
        temp->link = deleted->link;
        free(deleted);
    }
    printf("\n\nThe new linked list: ");
    printingLinkedList();
}

void delete_node_with_key()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    int key;
    printf("\n\nEnter the key of node to be deleted: ");
    scanf("%d", &key);

    node *temp = head;
    int count = 0;

    while (temp->value != key)
    {
        temp = temp->link;
        count++;
    }

    temp = head;
    for (int i = 0; i < count - 1; i++)
    {
        temp = temp->link;
    }
    node *deleted = temp->link;
    temp->link = deleted->link;
    free(deleted);
    printf("\nThe new linked list: ");
    printingLinkedList();
}

void count_num_of_node()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    node *temp = head;

    int count = 0; // to exculde when the temp becomes NULL in loop

    while (temp != 0)
    {
        temp = temp->link;
        count++;
    }
    printf("\n\nThe number of Nodes in linked list: %d", count);
}

void search_for_ele()
{
    printf("\n\nThe given linked list: ");
    printingLinkedList();
    int query;
    printf("\n\nEnter the number to query: ");
    scanf("%d", &query);

    node *temp = head;
    int count = 1;
    while (temp->value != query)
    {
        temp = temp->link;
        count++;
    }
    printf("\nThe number %d is on Position: %d", query, count);
}

void insert_node_beginning_end_any()
{
    int newChoice;
    printf("\n\nEnter 1 to Insert node at the beginning\n");
    printf("Enter 2 to insert node at the ending\n");
    printf("Enter 3 to insert node at certain position\n");
    printf("Enter your choice: ");
    scanf("%d", &newChoice);
    switch (newChoice)
    {
    case 1:
        insert_node_at_beginning();
        break;
    case 2:
        insert_node_at_end();
        break;
    case 3:
        insert_node_at_position();
        break;
    default:
        printf("\n\nError wrong number Entered!");
        break;
    }
}

void delete_node_beginning_end_any()
{
    int newChoice;
    printf("\n\nEnter 1 to delete node at the beginning\n");
    printf("Enter 2 to delete node at the ending\n");
    printf("Enter 3 to delete node at certain position\n");
    printf("Enter your choice: ");
    scanf("%d", &newChoice);
    switch (newChoice)
    {
    case 1:
        delete_node_at_beginning();
        break;
    case 2:
        delete_node_at_end();
        break;
    case 3:
        delete_node_at_position();
        break;
    default:
        printf("\n\nError wrong number Entered!");
        break;
    }
}