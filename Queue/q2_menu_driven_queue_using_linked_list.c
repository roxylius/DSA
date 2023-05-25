#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node
{
    int val;
    struct queue_node *next;
} qn;

int size;
qn *front = NULL;
qn *back = NULL;

qn *create_new_node(int val)
{
    qn *newNode = malloc(sizeof(qn));
    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

int isFull()
{
    int count = 0;
    qn *temp = front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (count >= size)
    {
        printf("\nQueue overflow\n");
        return 1;
    }
    else
    {
        return 0;
        printf("\nThe given queue is not empty!\n");
    }
}

void isEmpty()
{
    if (front == NULL)
        printf("\nThe given queue is Empty!\n");
    else
        printf("\nThe given queue is not empty!\n");
}

void enqueue()
{
    if (!isFull())
    {
        int val;
        printf("\nEnter val to enqueue: ");
        scanf("%d", &val);
        printf("\n");

        if (front == NULL)
        {
            front = create_new_node(val);
        }
        else
        {
            qn *temp = front;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = create_new_node(val);
        }
    }
}

void dequeue()
{
    if (front == NULL)
        printf("\nSTack Underflow!\n");
    else
    {
        qn *temp = front->next;
        free(front);
        front = temp;
    }
}

void display()
{
    if (front == NULL)
        printf("\nThe Stack is empty!\n");
    else
    {
        qn *temp = front;
        printf("\nTHe given queue: ");
        while (temp != NULL)
        {
            printf("%d - ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek(){
    if(front == NULL)
        printf("\nThe given queue is empty!\n");
    else
        {
            int pos,count = 1;
            printf("\nEnter pos to peek: ");
            scanf("%d",&pos);
            qn *temp = front;
            while(count != pos){
                temp = temp->next;
                count++;
            }
            printf("\nThe Element at pos[%d]: %d\n",pos,temp->val);
        }
}

int main()
{
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    while (1)
    {
        int choice;
        printf("\nEnter 1 to Enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display of elements\n");
        printf("Enter 5 to is empty\n");
        printf("Enter 6 to check is full\n");
        printf("Enter 7 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            isEmpty();
            break;

        case 6:
            if(!isFull())    
                printf("\nTHe given queue is Full!\n");
            break;

        case 7:
            exit(0);

        default:
            printf("\nWrong number entered!");
            break;
        }
    }
}