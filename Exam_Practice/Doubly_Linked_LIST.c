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

typedef struct Node node;

void reverse_display(node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverse_display(head->next);
    printf("%d \t", head->data);
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int count = 0;
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
            count++;
        }
        printf("\nNumber of nodes in the list = %d\n", count);
    }
}

node *front(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        return new_node;
    }
}

node *back(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
        return head;
    }
}

node *position(node *head, int pos, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (pos == 1)
    {
        node *temp = head;
        new_node->next = head;
        new_node->prev = head->prev;
        return new_node;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        return head;
    }
}

node *delete_at_front(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        node *temp = head;
        head = head->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        return head;
    }
}

node *delete_at_end(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Deleted element is %d\n", head->data);
        free(head);
        return NULL;
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted element is %d\n", temp->data);
        prev->next = NULL;
        free(temp);
        return head;
    }
}

node *delete_at_position(node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else if (pos == 1)
    {
        node *temp = head;
        head = temp->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        return head;
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        while (pos > 1 && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = temp->next;
        printf("Deleted element is %d\n", temp->data);
        return head;
    }
}

int main()
{
    int a, b, c;
    node *head = NULL;
    for (int i = 0; i < 4; i++)
    {
        head = front(head, i);
        head = position(head, 2, 32);
    }
    printf("reverse display : ");
    reverse_display(head);
    printf("\n");
    display(head);
    head = position(head, 1, 441);
    display(head);
    head = delete_at_front(head);
    display(head);
    head = delete_at_end(head);
    display(head);
    head = delete_at_position(head, 2);
    display(head);

    return 0;
}