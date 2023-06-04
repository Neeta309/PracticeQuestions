#include <stdio.h>
#include <stdlib.h>
#define size 5
int TOP = -1;
int stack[size];
void push()
{

    if (TOP == -1)
    {
        int value;
        printf("Enter value :");
        scanf("%d", &value);
        TOP = TOP + 1;
        stack[TOP] = value;
    }
    else if (TOP == size - 1)
    {
        printf("Stack is Full\n");
    }
    else
    {

        int value;
        printf("Enter value :");
        scanf("%d", &value);
        TOP = TOP + 1;
        stack[TOP] = value;
    }
}
void pop()
{
    if (TOP == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d value is deleted\n", stack[TOP]);
        TOP = TOP - 1;
    }
}
void display()
{
    if (TOP == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i = TOP; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("Choose any option \n1 for insert any element\n2 for delete any element\n3 for Display any element\n4 for Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("Enter correct value");
            break;
        }
    }

    return 0;
}