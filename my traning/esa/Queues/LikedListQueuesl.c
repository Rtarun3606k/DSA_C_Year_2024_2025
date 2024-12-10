#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct LikedListQueuesl
{
    int data;
    struct LikedListQueuesl *next;
};

typedef struct LikedListQueuesl Node;

Node *front = NULL;
Node *rear = NULL;

int enqueue(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {

        return 0;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("queue is empty \n");
        return 0;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);
        return 1;
    }
}

void display()
{
    if (front == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        Node *temp = front;
        printf("Queue elements are:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int a, b, c;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Diaplay\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &b);
            c = enqueue(b);
            if (c == 0)
            {
                printf("Queue is full\n");
            }
            break;
        case 2:
            c = dequeue();
            if (c == 0)
            {
                printf("Queue is empty\n");
            }
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