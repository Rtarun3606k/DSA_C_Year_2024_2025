#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct DoubleEndedQueuesLinkedList
{
    int data;
    struct DoubleEndedQueuesLinkedList *next, *prev;
};

typedef struct DoubleEndedQueuesLinkedList Node;

Node *front = NULL;
Node *rear = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
}

void *insertAtFrontOfQueue(int data)
{
    if (front == NULL)
    {
        front = rear = createNode(data);
    }
    else
    {
        Node *newNode = createNode(data);
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void *insertAtEndOfQueue(int data)
{
    if (front == NULL)
    {
        front = rear = createNode(data);
    }
    else
    {
        Node *newNode = createNode(data);
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

int dequeueAtFront()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }

    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);
        return 1;
    }
}

int dequeueAtEnd()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }

    else
    {
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
        return 1;
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
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
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Dequeue at front\n");
        printf("4. Dequeue at end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &b);
            insertAtFrontOfQueue(b);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &b);
            insertAtEndOfQueue(b);
            break;
        case 3:
            dequeueAtFront();
            break;
        case 4:
            dequeueAtEnd();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}