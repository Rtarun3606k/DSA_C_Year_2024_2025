#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct BST_iterative
{
    int data;
    struct BST_iterative *left;
    struct BST_iterative *right;
};
typedef struct BST_iterative node;

typedef struct stack
{
    node *stack[MAX];
    int top;
};

void push(node *item, struct stack *s)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    s->top = s->top + 1;
    s->stack[s->top] = item;
}

node *create_node()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int *pop(struct stack *s)
{
    node *item;
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    item = s->stack[s->top];
    s->top = s->top - 1;
    return item;
}

int main()
{
    int a, b, c;

    return 0;
}