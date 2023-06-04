#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure of stack
struct Stack
{
    int top;
    float arr[MAX_SIZE];
};

// Function to check if stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element to stack
void push(struct Stack *stack, float num)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = num;
}

// Function to pop an element from stack
float pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    float num = stack->arr[stack->top];
    stack->top--;
    return num;
}

// Function to evaluate a postfix expression
float evaluate(char *expr)
{
    struct Stack stack = {-1, {0}};
    int n = strlen(expr);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(expr[i]))
        {
            float num = 0;
            while (isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            push(&stack, num);
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            float op1 = pop(&stack);
            float op2 = pop(&stack);
            switch (expr[i])
            {
            case '+':
                push(&stack, op2 + op1);
                break;
            case '-':
                push(&stack, op2 - op1);
                break;
            case '*':
                push(&stack, op2 * op1);
                break;
            case '/':
                push(&stack, op2 / op1);
                break;
            default:
                printf("Invalid operator!\n");
                exit(1);
            }
        }
    }
    return pop(&stack);
}

// Main function
int main()
{
    char expr[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(expr, MAX_SIZE, stdin);
    printf("Result: %.2f\n", evaluate(expr));
    return 0;
}
