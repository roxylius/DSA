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
    return;
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
int count_size_of_ll()
{
    if (head == NULL) // if the linked list is empty
        return 0;

    int size = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
void traversing_list_forward()
{
    node *temp = head;
    int i, idxOfList = 0;
    printf("\nEnter the index of node to traverse: ");
    scanf("%d", &i);

    printf("\nThe given linked list: ");
    display_list();

    printf("\n\nThe node at index %d: ", i);

    while (temp != NULL)
    {
        if ((idxOfList++ + 1) == i) // as when the idx is 0 it prints the 1st node to print val of nth node i == (idx+1)
            printf("%d", temp->data);

        temp = temp->next;
    }
}

void traversing_list_backward()
{
    node *temp = head;
    int i, idxOfList = 1;
    printf("\nEnter the index of node to traverse backward: ");
    scanf("%d", &i);

    printf("\nThe given linked list: ");
    display_list();

    printf("\n\nThe node at index %d from back: ", i);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        if ((idxOfList++) == i) // as when the idx is 0 it prints the 1st node to print val of nth node i == (idx+1)
            printf("%d", temp->data);

        temp = temp->prev;
    }
}

void check_if_empty()
{
    if (head == NULL)
        printf("\n\nThe given linked list is EMPTY!");
    else
        printf("\n\nThe given linked list is NOT EMPTY!");
}

void insert_node_at_position(int pos)
{
    int num;
    node *temp;
    printf("\n\nEnter the val of node to be inserted = ");
    scanf("%d", &num);
    temp = create_new_node(num);

    if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (pos == (count_size_of_ll() + 1))
    {
        node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = temp;
        temp->prev = cur;
    }
    else
    {
        int pos;
        printf("Enter the pos to be inserted At: ");
        scanf("%d", &pos);
        node *cur = head;
        // if the entered pos is greater than size and less than 1
        if (pos > (count_size_of_ll() + 1) || pos < 1)
            return;

        if (pos == 1)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else if (pos == count_size_of_ll() + 1)
        {
            while (cur->next != NULL)
                cur = cur->next;

            cur->next = temp;
            temp->prev = cur;
        }
        else
        {
            int i = 1;
            while (cur != NULL)
            {
                if (pos == i)
                    break;

                cur = cur->next;
                i++;
            }
            node *prev = cur->prev;

            temp->next = cur;
            temp->prev = prev;
            prev->next = temp;
            cur->prev = temp;
        }
    }
    printf("\nThe given linked list: ");
    display_list();
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
        insert_node_at_position(1);
        break;
    case 2:
        insert_node_at_position(count_size_of_ll() + 1);
        break;
    case 3:
        insert_node_at_position(0);
        break;
    default:
        printf("\n\nError wrong number Entered!");
        break;
    }
}

void delete_node_at_beginning()
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

    printf("\nThe new linked list :");
    display_list();
}

void delete_node_at_end()
{
    node *cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    node *temp = cur;
    cur->prev->next = NULL;
    free(temp);

    printf("\nThe new linked list :");
    display_list();
}

void delete_node_at_position()
{
    int pos;
    printf("\nEnter the pos of node to be deleted: ");
    scanf("%d", &pos);

    if (pos > count_size_of_ll() || pos < 1)
        return;

    if (pos == 1)
        delete_node_at_beginning();
    else if (pos == count_size_of_ll())
        delete_node_at_end();
    else
    {
        int i = 1;
        node *cur = head;
        while (cur != NULL)
        {
            if (pos == i)
                break;

            cur = cur->next;
            i++;
        }
        node *temp = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(temp);
    }
    printf("\nThe new linked list :");
    display_list();
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

void delete_node_with_key()
{
    int key, isKey = 0;
    node *cur = head;
    printf("\n\nEnter the value of key: ");
    scanf("%d", &key);

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            isKey = 1;
            break;
        }

        cur = cur->next;
    }

    if (isKey == 0) // if there is no element with that key
    {
        printf("\n\nNo such node with this key");
        return;
    }

    // node *temp = cur;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);

    printf("\nThe new linked list :");
    display_list();
};

void count_num_of_node()
{
    printf("\n\nThe number of nodes in the linked list: %d", count_size_of_ll());
}

void search_for_ele()
{
    int query, isQuery = 0, idx = 1;
    printf("\n\nEnter the value of node to search: ");
    scanf("%d", &query);
    node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == query)
        {
            isQuery = 1;
            break;
        }
        cur = cur->next;
        idx++;
    }
    printf("\nThe number %d is on position = %d (forward) ", query, idx);
}

int main()
{
    create_doubly_linked_list();
    display_list();
    int choiceNum;
    printf("\n\nEnter 1 for Traversal of the list forward\n");
    printf("Enter 2 for Traversal of the list backward\n");
    printf("Enter 3 to Insert a node at the certain position(beginning,end,any)\n");
    printf("Enter 4 to Delete a node at the certain position(beginning,end,any)\n");
    printf("Enter 5 to Delete a node for given key\n");
    printf("Enter 6 to Count the total number of nodes\n");
    printf("Enter 7 to Search for an element in linked list\n");
    printf("Enter your Choice: ");
    scanf("%d", &choiceNum);

    switch (choiceNum)
    {
    case 1:
        traversing_list_forward();
        break;

    case 2:
        traversing_list_backward();
        break;

    case 3:
        insert_node_beginning_end_any();
        break;

    case 4:
        delete_node_beginning_end_any();
        break;

    case 5:
        delete_node_with_key();
        break;

    case 6:
        count_num_of_node();
        break;

    case 7:
        search_for_ele();
        break;

    default:
        printf("\n\nError wrong number Entered!");
        break;
    }

    return 0;
}