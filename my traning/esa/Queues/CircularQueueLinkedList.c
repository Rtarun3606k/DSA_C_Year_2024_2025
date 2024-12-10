#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct CircularQueueLinkedList
{
    int front, rear, size;
    int *arr;
};

typedef struct CircularQueueLinkedList Node;

void enqueue(Node *queue, int data)
{
    if ((queue->rear + 1) % queue->size == queue->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = data;
    }
}

void dequeue(Node *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
}

void display(Node *queue)
{
    if (queue->front == -1)

    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % queue->size)
        {
            printf("%d ", queue->arr[i]);
        }
        printf("%d ", queue->arr[i]);
    }
}

int main()
{
    int a, b, c;
    printf("Enter the size of the queue: ");
    scanf("%d", &a);
    Node *queue = (Node *)malloc(sizeof(Node));
    queue->size = a;
    queue->front = queue->rear = -1;
    queue->arr = (int *)malloc(sizeof(int) * queue->size);
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            printf("Enter the element to be enqueued: ");
            scanf("%d", &c);
            enqueue(queue, c);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}