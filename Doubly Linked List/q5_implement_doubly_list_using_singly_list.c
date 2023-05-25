#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node node;

node *head = NULL;
node *cur = NULL;

node *create_new_node(int val){
    node *newNode = (node *)malloc(sizeof(node));;
    newNode->data = val;
    newNode->link = NULL;

    return newNode;
}

void moveForward(){
    if(cur->link == NULL){
        printf("\nCant move forward!");
    }
    else{
        cur = cur->link;
        printf("\nNow at node: %d",cur->data);
    }
}

void moveBackward(){
    if(cur == head){
        printf("\nCant move backward");
    }
    else{
        node *temp = head;
        node *prev = NULL;
        while(temp != cur)
        {
            prev = temp;
            temp = temp->link;
        }
        cur = prev;
        printf("\nNow at node: %d",cur->data);
    }
}

void move(){
    int choice;
    printf("\nEnter 1 to move forward\n");
    printf("Enter 2 to move backward\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            moveForward();
            break;
        case 2:
            moveBackward();
            break;
        default:
            printf("\nWrong val input!");
            break;
    }
};

void add(){
    int val;
    printf("\nEnter val to insert: ");
    scanf("%d",&val);
    if(head == NULL)
    {
        head = create_new_node(val);
        cur = head;
    }
    else{
        cur->link = create_new_node(val);
        cur = cur->link;
    }
};

void display(){
    node *temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d - ",temp->data);
        printf("\b\b ");
        temp = temp->link;
    }
    printf("\nThe current node: %d",cur->data);
};

void release(){
    node *temp = head;
    node *prev = NULL;

    while(temp != cur){
        prev = temp;
        temp = temp->link;
    }

    if(temp->link == NULL){
        free(temp);
        prev->link = NULL;
        cur = prev;
    }else if(prev == NULL){  
        head = temp->link; 
        free(temp);
        cur = head;
    }else{
        prev->link = cur->link;
        cur = prev;
        free(temp);
    }
    display();
};

int main(){
    int choice;
    start:
    printf("\n\nEnter 1 to move\n");
    printf("Enter 2 to insert\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to release\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            move();
            goto start;
        case 2:
            add();
            goto start;
        case 3:
            display();
            goto start;
        case 4:
            release();
            goto start;
        default:
            printf("\nWrong number Entered!");
            goto start;
    }
    return 0;
}