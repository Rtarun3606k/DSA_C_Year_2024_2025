#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(node *top)
{
    return 0; // A linked list stack is never full until memory is exhausted
}

node *push(node *top, int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Stack Overflow\n");
        return top;
    }
    n->data = data;
    n->next = top;
    top = n;
    return top;
}

node *pop(node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return top;
    }
    else
    {
        node *n = top;
        top = top->next;
        printf("The element %d is popped\n", n->data);
        free(n);
        return top;
    }
}

void display(node *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main()
{

    node *top = NULL;
    for (int i = 0; i < 10; i++)
    {
        top = push(top, i);
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        top = pop(top);
    }

    display(top);

    int a, b, c;

    return 0;
}