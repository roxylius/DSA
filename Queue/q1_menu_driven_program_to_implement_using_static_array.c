// write a menu driven program to implement queue operations such as Enqueue, Peek , display of elements, isEmpty,isFull using static array
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int l;
    int size;
} q;

void enqueue(int *queue)
{
    // if the queue is full
    if (q.l >= q.size)
    {
        printf("\nqueue Overflow!\n");
    }
    else
    {
        if(q.f == -1){
            q.f++;
            q.l++;
        }
        int val;
        printf("\nEnter the number to enqueue: ");
        scanf("%d", &val);
        queue[q.l++] = val;
        printf("\n");
    }
}

void dequeue(int *queue)
{
    // if the queue is empty
    if (q.f == q.l)
    {
        printf("\nQueue Underflow!\n");
    }
    else
    {
        q.f++;
    }
}

void display(int *queue)
{
    printf("\nThe given queue-> ");
    for (int i = q.f; i < q.l; i++)
        printf("%d - ", queue[i]);
    printf("\n");
}

void peek(int *queue)
{
    int pos;
    printf("\nEnter the value to peek: ");
    scanf("%d", &pos);
    printf("\nThe number at %d is %d\n",pos,queue[q.f + pos]);
}

void isFull(int *queue){
    if(q.f >= q.size)
        printf("\nThe given queue is full\n");
    else 
        printf("\nThe given queue is not full!\n");
}

void isEmpty(int *queue){
    if(q.f == q.l){
        printf("\nThe given queue is Empty!\n");
    }
    else {
        printf("\nThe given queue is not Empty!\n");
    }
}

int main()
{

    q.f = -1;
    q.l = -1;
    // enter the size of queue
    printf("Enter the size of queue: ");
    scanf("%d", &q.size);

    // creating the queue
    int queue[q.size];

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
        scanf("%d",&choice);

        switch(choice){
            case 1:
            enqueue(queue);
            break;

            case 2:
            dequeue(queue);
            break;

            case 3:
            peek(queue);
            break;

            case 4:
            display(queue);
            break;

            case 5:
            isEmpty(queue);
            break;

            case 6:
            isFull(queue);
            break;

            case 7:
            exit(0);

            default:
            printf("\nWrong number entered!");
            break;
        }
    }
}