#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *enque(struct Node *front, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        struct Node *p = front;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return front;
}

struct Node *deque(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}

void display(struct Node *front)
{
    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Emplty Queue");
    }
    else
    {
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
    struct Node *front = NULL;
    for (int i = 0; i < 5; i++)
    {
        front = enque(front, i * 2);
    }
    display(front);
    front = deque(front);
    // printf("\n");
    display(front);

    return 0;
}