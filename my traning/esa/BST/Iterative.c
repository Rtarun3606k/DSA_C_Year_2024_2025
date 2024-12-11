#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

typedef struct stack
{
    NODE *stack[MAX];
    int top;
} STACK;

void push(NODE *t, STACK *s)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->stack[++(s->top)] = t;
    }
}

NODE *pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    else
    {
        return s->stack[(s->top)--];
    }
}

NODE *createNode(int data)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

int isEmpty(NODE *t)
{
    return (t == NULL);
}

NODE *insertNode(NODE *root, int data)
{
    if (isEmpty(root))
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorder(NODE *t)
{
    if (isEmpty(t))
    {
        return;
    }
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top = -1;
    NODE *temp = NULL;
    do
    {
        while (t)
        {
            push(t, s);
            t = t->left;
        }
        temp = pop(s);
        if (temp)
        {
            printf("%d ", temp->data);
            t = temp->right;
        }
    } while (t != NULL || s->top != -1);
    free(s);
}

void preorder(NODE *t)
{
    if (isEmpty(t))
    {
        return;
    }
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top = -1;
    push(t, s);
    while (s->top != -1)
    {
        NODE *temp = pop(s);
        printf("%d ", temp->data);
        if (temp->right)
        {
            push(temp->right, s);
        }
        if (temp->left)
        {
            push(temp->left, s);
        }
    }
    free(s);
}

void postorder(NODE *t)
{
    if (isEmpty(t))
    {
        printf("Tree is empty\n");
        return;
    }
    STACK *s1 = (STACK *)malloc(sizeof(STACK));
    STACK *s2 = (STACK *)malloc(sizeof(STACK));
    s1->top = -1;
    s2->top = -1;
    NODE *temp = NULL;
    push(t, s1);
    while (s1->top != -1)
    {
        temp = pop(s1);
        push(temp, s2);
        if (temp->left)
        {
            push(temp->left, s1);
        }
        if (temp->right)
        {
            push(temp->right, s1);
        }
    }
    while (s2->top != -1)
    {
        temp = pop(s2);
        printf("%d ", temp->data);
    }
    free(s1);
    free(s2);
}

int main()
{
    NODE *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}