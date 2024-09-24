#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

// Stack structure
typedef struct
{
    int data[MAX];
    int top;
} Stack;

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1; // Indicates stack underflow
    }
    return s->data[s->top--];
}

// Function to push an element into the stack
void push(Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->data[++s->top] = value;
    }
}

// Function to evaluate the postfix expression
int eval(char *postfix)
{
    Stack s;
    s.top = -1;
    int i = 0, op1, op2, result;

    while (postfix[i] != '\0')
    {
        // If the character is a digit, push it onto the stack
        if (isdigit(postfix[i]))
        {
            push(&s, postfix[i] - '0');
        }
        // If the character is an operator, pop two elements and apply the operator
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);

            if (op1 == -1 || op2 == -1)
            {
                // Error: Trying to pop from empty stack
                return -1; // Indicating error
            }

            switch (postfix[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Division by zero error\n");
                    return -1; // Indicating error
                }
                result = op1 / op2;
                break;
            default:
                printf("Invalid operator\n");
                return -1; // Indicating error
            }
            push(&s, result);
        }
        i++;
    }

    // The final result should be the only element in the stack
    return pop(&s);
}

// Function to print the result after evaluating the postfix expression
void disp(int result)
{
    if (result != -1)
    {
        printf("%d\n", result);
    }
}

int main()
{
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = eval(postfix);
    disp(result);

    return 0;
}