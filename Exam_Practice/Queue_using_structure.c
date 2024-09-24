#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
typedef struct Queue queue;

int isFull(queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(queue *q, int data)
{

    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
    }
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    q->f++;
    printf("the element dequed was %d \n ", q->arr[q->f]);
    return;
}

void disaplay(queue *q)
{

    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enque(&q, 12);
    enque(&q, 13);
    dequeue(&q);
    disaplay(&q);

    int a, b, c;

    return 0;
}