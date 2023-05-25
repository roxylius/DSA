#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

struct stack st;

void pop()
{
    if (st.top == -1)
        printf("\nStack underflow!Unable to pop!");
    else
    {
        printf("\nPopped the element!");
        st.top--;
    }
}

void push(int val)
{
    if (st.top >= st.size - 1)
        printf("\nStack overflow!unable to push!");
    else
    {
        st.array[++st.top] = val;
    }
}
void isEmpty()
{
    if (st.top == -1)
        printf("\nThe given stack is EMPTY!");
    else
        printf("\nThe given stack is not EMPTY!");
}

void display()
{
    if (st.top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nThe stack->\n");
        for (int i = st.top; i >= 0; i--)
        {
            printf("%02d\n", st.array[i]);
        }
    }
}

int main()
{
    st.top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &st.size);
    st.size = 5;
    st.array = malloc(st.size * sizeof(int));
    int choice, val;
restart:
    printf("\n\nEnter 1 for push\n");
    printf("Enter 2 for pop\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 to check if stack is empty\n");
    printf("Enter 5 to exit");
    printf("\n\nEnter ur choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter val to push: ");
        scanf("%d", &val);
        push(val);
        goto restart;

    case 2:
        pop();
        goto restart;

    case 3:
        display();
        goto restart;

    case 4:
        isEmpty();
        goto restart;

    case 5:
        break;

    default:
        printf("\nWRONG NUMBER ENTERED!");
        goto restart;
    }

    return 0;
}