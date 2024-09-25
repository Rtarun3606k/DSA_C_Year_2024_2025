#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Queues_using_linked_list
{
    int data;
    struct Queues_using_linked_list *next;
};

typedef struct Queues_using_linked_list Queues;

Queues *front = NULL;
Queues *reare = NULL;

void display()
{
    Queues *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int data)
{
    if (front == NULL)
    {
        Queues *n = (Queues *)malloc(sizeof(Queues));
        n->data = data;
        n->next = NULL;
        front = reare = n;
    }
    else
    {
        Queues *n = (Queues *)malloc(sizeof(Queues));
        n->data = data;
        n->next = NULL;
        reare->next = n;
        reare = n;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        Queues *n = front;
        front = front->next;
        printf("The element %d is dequeued\n", n->data);
        free(n);
    }
}

int main()
{
    int a, b, c;
    enqueue(10);
    enqueue(10);
    dequeue();
    display();

    return 0;
}