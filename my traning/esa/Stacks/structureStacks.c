#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct structureStacks
{
    int *stactArray;
    int top;
    int size;
};

typedef struct structureStacks Stacks;

int push(Stacks *s, int data)
{
    if (s->top == s->size - 1)
    {
        printf("Stack is full\n");
        return 0;
    }
    else
    {
        s->top = s->top + 1;
        s->stactArray[s->top] = data;
        return s->stactArray[s->top];
    }
}

int pop(Stacks *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        int store = s->stactArray[s->top];
        s->top = s->top - 1;
        return store;
    }
}

void display(Stacks *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i < s->top + 1; i++)
        {
            printf("%d ", s->stactArray[i]);
        }
    }
}
int main()
{
    int a, b, c;
    Stacks s;
    printf("Enter the number of elements you want to push: ");
    scanf("%d", &a);
    s.size = a;
    s.stactArray = malloc(sizeof(int) * a);
    s.top = -1;
    for (int i = 0; i < a; i++)
    {
        printf("Enter the element you want to push: ");
        scanf("%d", &b);
        push(&s, b);
    }
    display(&s);
    printf("\n");
    printf("enter the number of elements you want to pop : ");
    scanf("%d", &b);
    printf("\n");
    for (int i = 0; i < b; i++)
    {
        pop(&s);
    }
    display(&s);

    return 0;
}