#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int pop(int *s, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        int store = s[*top];
        *top = *top - 1;
        return store;
    }
}

int push(int *s, int *top, int size, int data)
{
    if (*top == size - 1)
    {
        printf("Stack is full\n");
        return 0;
    }
    else
    {
        *top = *top + 1;
        s[*top] = data;
        return s[*top];
    }
}

void display(int *s, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i <= *top; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int a, b, c;
    int top = -1;
    printf("Enter the number of elements you want to push: ");
    scanf("%d", &a);
    int *s = (int *)malloc(sizeof(int) * a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter the element you want to push: ");
        scanf("%d", &b);
        push(s, &top, a, b);
    }
    display(s, &top);
    printf("Enter the number of elements you want to pop: ");
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        pop(s, &top);
    }
    display(s, &top);

    return 0;
}