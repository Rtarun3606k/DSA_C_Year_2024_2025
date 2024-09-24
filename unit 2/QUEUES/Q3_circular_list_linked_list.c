#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct CircularNode
{
    int data;
    struct CircularNode *next;
    struct CircularNode *prev;
} CircularNode;

struct CircularNode *enque(CircularNode *front, int data)
{
    CircularNode *temp = (CircularNode *)malloc(sizeof(CircularNode));
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (front == NULL)
    {
        front = temp;
        front->next = front;
        front->prev = front;
    }
    else
    {
        CircularNode *p = front;
        while (p->next != front)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
        temp->next = front;
        front->prev = temp;
    }
    return front;
}

void display(struct CircularNode *front)
{
    CircularNode *temp = front;
    if (temp == NULL)
    {
        printf("Empty Queue");
    }
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
}

CircularNode *deque(CircularNode *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        CircularNode *temp = front;
        front = front->next;
        CircularNode *last = front->prev;
        last->next = front;
        front->prev = last;
    }

    return front;
}

int main()
{
    int a, b, c;
    CircularNode *front = NULL;
    for (int i = 0; i < 5; i++)
    {
        front = enque(front, i * 2);
    }
    display(front);

    // Add a line of code to dequeue an element
    front = deque(front);
    display(front);

    return 0;
}