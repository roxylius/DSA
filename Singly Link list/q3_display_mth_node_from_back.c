#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *link;
};
typedef struct node node;

node *create_new_node(int val){
    node *newNode = malloc(sizeof(node));
    newNode->value = val;
    newNode->link = NULL;

    return newNode;
}

void printLinkList(node **head){
    node *temp = *head;
    while (temp != NULL)
    {
        printf("%d - ",temp->value);
        temp = temp->link;
    }
    printf("\b\b " );
    free(temp);
}

int sizeOfLL(node *head){
    node *temp = head;
    int size = 1; 
    while(temp->link != NULL){
        temp = temp->link;
        size++;
    }
    return size;
}

void takingVal(node **head){
    int val;
    node *temp;
    printf("Enter val for linked list and Enter 0 to stop ->\n" );
    int i = 0;
    while (1)
    {
        printf("val[%d]: ",++i);
        scanf("%d",&val);

        if(val == 0)
            break;
        else{
            if (i == 1)
            {
                *head = create_new_node(val);
                temp = *head;
            }
            else
            {
                temp->link = create_new_node(val);
                temp = temp->link;
            }
        }
    }
}


void displayMthFromEnd(node *head){

}

int main(){
    //taking values of linked list
    node *head;
    takingVal(&head);

    //taking the value of mth node from back
    int mth;
    printf("\n\nEnter the index of node from back: ");
    scanf("%d",&mth);

    //printing linked list
    printLinkList(&head);

    //finding mth node from back
    int indexOfMth = sizeOfLL(head) - mth;

    node *temp = head;
    for (int i = 0; i < indexOfMth; i++)
        temp = temp->link;
        
    printf("\n\nThe %d node from back of linked list: %d",mth,temp->value);

    return 0;
}