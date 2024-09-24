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
    struct Node *new_node = (struct Node *)malloc((sizeof(struct Node)));
    new_node->val = data;
    new_node->next = new_node;
    if (head == NULL)
    {
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
        printf("\nlist is : ");
        do
        {
            printf("%d\t", temp->val);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

struct Node *insert_at_position(struct Node *head, int data, int pos)
{
    struct Node *new_node = (struct Node *)malloc((sizeof(struct Node)));
    new_node->val = data;
    new_node->next = new_node;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        return head;
    }
}

struct Node *delete_front(struct Node *head)
{
    if (head == NULL)
    {
        printf("empty list");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp1 = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        free(temp1);
        return head;
    }
}

struct Node *delete_last(struct Node *head)
{
    if (head == NULL)
    {
        printf("empty list");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp1 = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
        free(temp->next);
        return head;
    }
}

struct Node *delete_specific_element(struct Node *head, int data)
{
    if (head == NULL)
    {
        printf("empty list");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp1 = head;
        while (temp->next != head && temp->val != data)
        {
            temp1 = temp;
            temp = temp->next;
        }
        if (temp->val == data)
        {
            temp1->next = temp->next;
            free(temp);
        }
        return head;
    }
}

struct Node *delete_at_position(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("empty list");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp1 = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        free(temp);
        return head;
    }
}

int main()
{
    int a, b, c;
    struct Node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insert(head, i * 4);
    }
    display(head);
    printf("Enter the value to insert : ");
    scanf("%d", &a);
    head = insert(head, a);
    display(head);
    printf("Enter the value to insert : ");
    scanf("%d", &b);
    printf("Enter the position to insert : ");
    scanf("%d", &c);
    head = delete_front(head);
    display(head);
    head = delete_last(head);
    display(head);
    head = delete_specific_element(head, 0);
    display(head);
    head = delete_at_position(head, 2);
    display(head);

    return 0;
}