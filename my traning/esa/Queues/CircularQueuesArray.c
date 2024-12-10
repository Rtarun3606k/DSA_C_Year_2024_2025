#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int rear = -1;
int front = -1;
int queue[MAX];

void enqueue(int data)
{
    if (front == -1)
    {
        front = 0;
    }
    else if ((rear + 1) % MAX == front)
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is full\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        printf("Queue elements are:\n");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main()
{
    int a, b, c;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &b);
            enqueue(b);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}