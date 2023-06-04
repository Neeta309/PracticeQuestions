#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure of stack
struct Stack
{
    int top;
    char arr[MAX_SIZE];
};

// Function to check if stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element to stack
void push(struct Stack *stack, char c)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = c;
}

// Function to pop an element from stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    char c = stack->arr[stack->top];
    stack->top--;
    return c;
}

// Function to check if parentheses are balanced
int isBalanced(char *str)
{
    struct Stack stack = {-1, ""};
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            push(&stack, str[i]);
        }
        else if (str[i] == ')')
        {
            if (isEmpty(&stack))
            {
                return 0;
            }
            else
            {
                pop(&stack);
            }
        }
    }
    return isEmpty(&stack);
}

// Main function
int main()
{
    char str[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);
    if (isBalanced(str))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }
    return 0;
}
