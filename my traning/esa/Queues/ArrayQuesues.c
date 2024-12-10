#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int enqueue(int *queue, int *rear, int data)
{
    if (*rear == MAX - 1)
    {
        printf("Queue is full\n");
        return 0;
    }
    else
    {
        queue[++*rear] = data;
        return 1;
    }
}

int dequeue(int *queue, int *front, int rear)
{
    if (*front > rear)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        (*front)++;
        return 1;
    }
}

void display(int *queue, int rear, int front)
{
    if (front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int data;
    int queue[MAX];
    int front = 0, rear = -1;
    int choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            if (enqueue(queue, &rear, data))
            {
                printf("Data enqueued successfully\n");
            }
            break;
        case 2:
            if (dequeue(queue, &front, rear))
            {
                printf("Data dequeued successfully\n");
            }
            break;
        case 3:
            display(queue, rear, front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}