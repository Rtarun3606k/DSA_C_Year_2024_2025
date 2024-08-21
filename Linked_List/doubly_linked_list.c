#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *create_node(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = temp;
        temp->prev = current;
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        printf("\nlist is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void display_reverse(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("\nlist in reverse is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
}

struct Node *insert_at_beginig(struct Node *head, int data)
{

    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
    return head;
}

struct Node *insert_at_pos(struct Node *head, int data, int pos)
{
    if (pos == 1)
    {
        head = insert_at_beginig(head, data);
        return head;
    }

    struct Node *temp = malloc(sizeof(struct Node));
    struct Node *current = head;
    temp->data = data;
    for (int i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next->prev = temp;
    current->next = temp;
    temp->prev = current;
    return head;
}

struct Node *delete_front(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

int main()
{
    int a, b, c;
    struct Node *head = NULL;
    head = create_node(head, 10);
    head = create_node(head, 20);
    head = create_node(head, 30);
    display(head);
    display_reverse(head);
    head = insert_at_beginig(head, 5);
    display(head);
    display_reverse(head);
    head = insert_at_pos(head, 2, 2);
    display(head);
    display_reverse(head);
    head = delete_front(head);
    display(head);

    return 0;
}