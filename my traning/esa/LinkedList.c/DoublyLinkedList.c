#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtFront(int data, Node *head)
{
    if (head == NULL)
    {
        return createNode(data);
    }

    else
    {
        Node *newNode = createNode(data);
        head->prev = newNode;
        newNode->next = head;
        return newNode;
    }
}

Node *insertAtEnd(int data, Node *head)
{
    if (head == NULL)
    {
        return createNode(data);
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(data);
        temp->next->prev = temp;
        return head;
    }
}

Node *insertAtPosition(int data, int pos, Node *head)
{
    if (head == NULL)
    {
        return createNode(data);
    }
    else
    {
        Node *temp = head;
        Node *next = NULL;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        next = temp->next;
        temp->next = createNode(data);
        temp->next->prev = temp;
        temp->next->next = next;
        return head;
    }
}

Node *deleteAtFront(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        temp = temp->next;
        free(head);
        temp->prev = NULL;
        return temp;
    }
}

Node *deleteAtLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        return head;
    }
}

Node *deleteAtPosition(int position, Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        free(temp1);
        return head;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int a, b, c;
    Node *head = NULL;
    Node *head2 = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insertAtEnd(i * 2, head);
    }
    for (int i = 0; i < 5; i++)
    {
        head = insertAtFront(i * 2, head);
    }

    head = insertAtPosition(23, 3, head);
    head = deleteAtFront(head);
    head = deleteAtLast(head);
    head = deleteAtPosition(3, head);
    display(head);

    return 0;
}