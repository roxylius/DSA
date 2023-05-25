#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *link;
}node;

node *head = NULL;

node *create_new_node(int value){
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->link = NULL;

    return newNode;
}

void printLinkedList(){
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d - ",temp->value );
        temp = temp->link;
    }
    printf("\b\b ");
}

void takingVal()
{
    int val;
    printf("Enter values in link list and enter 0 to stop!\n" );
    int i = 0;
    node *temp;
    while (1)
    {
        printf("val[%d]: ",++i);    
        scanf("%d",&val);
        if (val == 0)
            break;   
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

void findDelAndInsert(){
    //taking the value of num to find
    int query;
    int isQuery = 0;
    printf("\nEnter the number to be deleted: " );
    scanf("%d",&query);

    //creating prev , current and next node
    int size = 0;
    node *prev = NULL;
    node *cur = head;
    node *next = NULL;
    while (cur != NULL)
    {
        next = cur->link;
        if (cur->value == query)
        {
            isQuery = 1;
            prev->link = next;
            node *temp = head;
            head = cur;
            cur->link = temp;
            break;
        }
        prev = cur;
        cur = next;
        size++;
    }
    

    if (isQuery == 0)
    {
        printf("\n\nThe number doesn't exist!" );
    }
    // else if(size == 1){
    //     printf("\n\nThe desired linked list:" );
    //     printLinkedList();
    // }
    else
    {
        printf("\n\nThe desired linked list: " );
        printLinkedList();
    }
    
}

int main()
{
    //taking values in linked list
    takingVal();

    //finding ,deleting and inserting element in the start 
    findDelAndInsert();
    return 0;
}