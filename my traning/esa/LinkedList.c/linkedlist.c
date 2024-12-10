#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

Node *insertAtEnd(int data, Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

Node *insertAtFront(int data, Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {

        return newNode;
    }
    else
    {
        newNode->next = head;

        return newNode;
    }
}

Node *insertAtPosition(int data, Node *head, int position)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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

Node *deleteAtFront(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
    }
}

Node *deleteAtPosition(Node *head, int position)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        free(head);
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
        free(temp1);
        return head;
    }
}

void countingNodesRecurssion(Node *head, int *count)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (head->next == NULL)
        {
            printf("Number of nodes in the linked list is %d\n", *count);
            return;
        }

        *count = *count + 1;
        countingNodesRecurssion(head->next, count);
    }
}

Node *mergeList(Node *head, Node *head1)
{
    if (head == NULL && head1 == NULL)
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
        temp->next = head1;
        return head;
    }
}

int main()
{
    int a, b, c;
    Node *head = NULL;
    Node *head2 = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insertAtEnd(i * 2, head);
        head2 = insertAtEnd(i * 2, head2);
    }
    for (int i = 1; i < 5 + 1; i++)
    {
        head = insertAtFront(i * 3, head);
    }
    display(head);
    printf("Before inserting at position\n");
    head = insertAtPosition(100, head, 3);
    display(head);
    printf("Before deleting at Front\n");
    head = deleteAtFront(head);
    display(head);
    printf("Before deleting at end\n");
    head = deleteAtEnd(head);
    display(head);
    printf("Before deleting at position\n");
    head = deleteAtPosition(head, 3);
    display(head);
    printf("Before merging the list\n");
    head = mergeList(head, head2);
    display(head);
    int count = 1;
    countingNodesRecurssion(head, &count);
    free(head);

    return 0;
}