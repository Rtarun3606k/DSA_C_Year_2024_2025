#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front, rear, size;
} Queue;

void enqueue(Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (q->front == -1) // If queue is initially empty
            q->front = 0;
        q->rear = q->rear + 1;
        q->arr[q->rear] = data;
    }
}

int dequeue(Queue *q)
{
    int a;
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        a = q->arr[q->front];
        q->front = q->front + 1;
        return a;
    }
}

int main()
{
    Queue q;
    q.size = 400;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    visited[0] = 1;
    enqueue(&q, 0);
    while (q.front != -1 && q.front <= q.rear)
    {
        int node = dequeue(&q);
        printf("%d ", node);
        for (int i = 0; i < 7; i++)
        {
            if (a[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }

    free(q.arr);

    return 0;
}
