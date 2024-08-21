#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = data;
    if (head == NULL)
    {
        new_node->next = new_node;
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

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("empty list");
    }
    else
    {
        struct Node *temp = head;
        do
        {
            printf("%d : %p\n", temp->val, temp->next);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

struct Node *insert_at_head(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = data;
    if (head == NULL)
    {
        new_node = new_node->next;
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
        return new_node;
    }
}

int main()
{
    int a, b, c;
    struct Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    display(head);
    head = insert_at_head(head, 6);
    display(head);

    return 0;
}