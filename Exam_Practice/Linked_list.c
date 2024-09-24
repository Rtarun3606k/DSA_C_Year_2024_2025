#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

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

void display_reverse(node *head)
{

    if (head == NULL)
    {
        return;
    }
    display_reverse(head->next);
    printf("%d \t", head->data);
}

node *insert_front(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        new_node->next = head;
        return new_node;
    }
}

node *insert_back(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
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
        return head;
    }
}

node *insert_at_position(node *head, int pos, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (pos == 1)
    {
        new_node->next = head;
        return new_node;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
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

node *merge_list(node *head, node *head1)
{
    if (head == NULL)
    {
        return head1;
    }
    if (head1 == NULL)
    {
        return head;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head1;
    return head;
}

int main()
{
    int a, b, c;
    node *head = NULL;
    node *head1 = NULL;
    node *merged = NULL;
    for (int i = 0; i < 4; i++)
    {
        head = insert_front(head, i);
        head1 = insert_front(head1, i);
    }
    for (int i = 0; i < 4; i++)
    {
        head = insert_back(head, i * 10);
        head1 = insert_back(head1, i * 10);
    }
    head = insert_at_position(head, 3, 23);
    display(head);
    printf("\n");
    display_reverse(head);
    printf("\n");
    head = delete_at_front(head);
    head = delete_at_end(head);
    head = delete_at_position(head, 3);
    printf("\n");
    display(head);
    printf("\nmerged list\n");
    merged = merge_list(head, head1);
    display(merged);
    return 0;
}