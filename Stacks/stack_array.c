#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int pop(int *, int);

int push(int *, int *, int, int);
void display(int *, int);
int peek(int *, int);

int main()
{
    int top, choice, k, size, x;
    int *s;
    printf("Enter the size of the stack:");
    scanf("%d", &size);
    s = (int *)malloc(size * sizeof(int));
    top = -1;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed:");
            scanf("%d", &x);
            top = push(s, &top, x, size);
            break;
        case 2:
            top = pop(s, top);
            break;
        case 3:
            display(s, top);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");

        case 5:
            printf("exiting..");
            break;
        }
    } while (choice != 5);

    return 0;
}

int push(int *s, int *t, int x, int size)
{
    if (*t == size - 1)
    {
        printf("Stack is full\n");
        return *t;
    }
    (*t)++;
    s[*t] = x;
    return *t;
}

int pop(int *s, int t)
{
    if (t == -1)
    {
        printf("Stack is empty\n");
        return t;
    }
    printf("Popped element is %d\n", s[t]);
    t--;
    return t;
}

int peek(int *s, int t)
{
    if (t == -1)
    {
        printf("Stack is empty\n");
        return t;
    }
    printf("Top element is %d\n", s[t]);
    return t;
}

void display(int *s, int t)
{
    int i;
    if (t == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = t; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}