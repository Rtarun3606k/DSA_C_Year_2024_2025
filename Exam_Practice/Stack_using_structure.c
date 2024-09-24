#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

typedef struct stack stack;

int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }

    return 0;
}

int isfull(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

// write a pop function
int pop(stack *s)
{
    if (isempty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        // s->top--;
        return val;
    }
}

void push(stack *s, int val)
{
    if (isfull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int main()
{
    int a, b, c;
    stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        s->arr[i] = i;
        s->top++;
    }
    printf("Stack is created\n");
    pop(s);
    pop(s);
    push(s, 10);
    for (int i = 0; i <= s->top; i++)
    {
        // s->arr[i] = i;
        printf("%d\n", s->arr[i]);
    }
    if (isempty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

    return 0;
}