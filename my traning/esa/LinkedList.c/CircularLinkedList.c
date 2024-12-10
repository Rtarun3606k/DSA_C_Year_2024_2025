#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct CircularLinkedList
{
    int data;
    struct CircularLinkedList *next;
};

typedef struct CircularLinkedList Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtFront(int data, Node *head)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return newNode;
    }
}

Node *insertAtEnd(int data, Node *head)
{
    if (head == NULL)
    {
        Node *newNode = createNode(data);
        newNode->next = newNode;
        return newNode;
    }
    else
    {
        Node *temp = head;
        Node *store = NULL;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        store = temp->next;
        temp->next = createNode(data);
        temp->next->next = store;
        return head;
    }
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
        return head;
    }
}

void display(Node *head)
{
    Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

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
    printf("Circular Linked List: ");
    display(head);
    for (int i = 0; i < 5; i++)
    {
        head = insertAtFront(i * 2, head);
    }
    printf("Circular Linked List: At Front ");
    display(head);
    head = deleteAtEnd(head);
    display(head);

    return 0;
}