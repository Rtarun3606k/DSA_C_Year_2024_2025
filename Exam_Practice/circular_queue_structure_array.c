#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 5

struct circular_queue_structure_array
{
    int front;
    int rear;
    int arr[SIZE];
};

typedef struct circular_queue_structure_array cqueue;

int isEmpty(cqueue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
    {
        printf("Queue is not empty\n");
        return 0;
    }
}

int isFull(cqueue *q)
{
    if (q->front == (q->rear + 1) % SIZE)
    {
        printf("Queue is full\n");
        return 1;
    }
    else
    {
        printf("Queue is not full\n");
        return 0;
    }
}

void display(cqueue *q)
{
    if (isEmpty(q))
    {
        return;
    }

    printf("\n");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);

        if (i == q->rear)
        {
            break;
        }

        i = (i + 1) % SIZE;
    }
}

void enqueue(cqueue *q, int value)
{
    if (isFull(q))
    {
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = value;
    printf("Enqueued element: %d\n", value);
}

void dequeue(cqueue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    printf("Dequeued element %d \n", q->arr[q->front]);
    q->front = (q->front + 1) % SIZE;
}

int main()
{
    int a, b, c;
    cqueue q;
    q.front = q.rear = -1;
    enqueue(&q, 10);
    display(&q);
    enqueue(&q, 20);
    display(&q);
    enqueue(&q, 10);
    display(&q);
    enqueue(&q, 20);
    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}