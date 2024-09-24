#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct Node node;

void display(node *head)
{
    if (head == NULL)
    {
        printf("\n list is emplty");
        return;
    }
    else
    {
        node *temp = head;
        printf("\n");
        do
        {
            printf("%d \t", temp->val);
            temp = temp->next;
        } while (temp != head);
    }
}

node *insert(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = data;
    if (head == NULL)
    {
        new_node->next = new_node; // Point to itself to make it circular
        return new_node;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        return head;
    }
}

node *delete_last(node *head)
{
    if (head == NULL)
    {
        printf("\n list is emplty");
        return NULL;
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp->next != head);
        prev->next = head;
        return head;
    }
}

int main()
{
    int a, b, c;
    node *head = NULL;
    for (int i = 0; i < 4; i++)
    {
        head = insert(head, i);
    }
    head = delete_last(head);
    display(head);

    return 0;
}