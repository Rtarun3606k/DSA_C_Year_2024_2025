#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
typedef struct node node_t;

struct deque
{
    node_t *front;
    node_t *rear;
};
typedef struct deque deque_t;

void display(deque_t *dq)
{
    if (dq->front == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    node_t *current = dq->front;
    printf("Deque elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_front(deque_t *dq, int x)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (dq->front == NULL)
    {
        dq->front = newNode;
        dq->rear = newNode;
    }
    else
    {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }

    printf("Element %d inserted at the front.\n", x);
}

void insert_rear(deque_t *dq, int x)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (dq->rear == NULL)
    {
        dq->front = newNode;
        dq->rear = newNode;
    }
    else
    {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }

    printf("Element %d inserted at the rear.\n", x);
}

int delete_front(deque_t *dq)
{
    if (dq->front == NULL)
    {
        printf("Deque is empty.\n");
        return -1;
    }

    int deletedData = dq->front->data;
    node_t *temp = dq->front;

    if (dq->front == dq->rear)
    {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else
    {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    printf("Element %d deleted from the front.\n", deletedData);
    return deletedData;
}

int delete_rear(deque_t *dq)
{
    if (dq->rear == NULL)
    {
        printf("Deque is empty.\n");
        return -1;
    }

    int deletedData = dq->rear->data;
    node_t *temp = dq->rear;

    if (dq->front == dq->rear)
    {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else
    {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    printf("Element %d deleted from the rear.\n", deletedData);
    return deletedData;
}

int main()
{
    int a, choose;
    deque_t dq;
    dq.front = NULL;
    dq.rear = NULL;

    do
    {
        printf("1. Insert at front\n2. Delete from front\n3. Delete from rear\n4. Display\n5. Insert at rear\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &a);
            insert_front(&dq, a);
            break;

        case 2:
            delete_front(&dq);
            break;

        case 3:
            delete_rear(&dq);
            break;

        case 4:
            display(&dq);
            break;

        case 5:
            printf("Enter data: ");
            scanf("%d", &a);
            insert_rear(&dq, a);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choose != 6);

    return 0;
}