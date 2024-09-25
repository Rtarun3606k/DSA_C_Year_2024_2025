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

node *f = NULL;
node *r = NULL;
void enqueue_end(int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = data;
    n->next = NULL;
    if (f == NULL)
    {
        f = r = n;
    }
    else
    {
        r->next = n;
        r = n;
    }
}

void enqueue_front(int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Memory allocation failed\n");
    }
    n->data = data;
    n->next = f;
    f = n;
}

void display()
{
    node *ptr = f;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void dqueue_front()
{
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }

    node *temp = f;
    f = f->next;
    printf("The element %d is dequeued\n", temp->data);
    free(temp);
}

void dequeue_end()
{
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    node *temp = f;
    node *rear = r;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    r = prev;

    printf("The element %d is dequeued\n", temp->data);
    free(temp);
}

int main()
{
    int a, b, c;
    enqueue_end(10);
    enqueue_end(20);
    display();
    enqueue_front(30);
    enqueue_front(40);
    display();
    dqueue_front();
    display();
    dequeue_end();
    display();

    return 0;
}