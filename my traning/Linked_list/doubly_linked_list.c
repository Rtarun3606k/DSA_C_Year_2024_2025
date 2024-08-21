#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct doubly_linked_list
{
    int val;
    struct doubly_linked_list *next;
    struct doubly_linked_list *prev;
};

struct doubly_linked_list *insert_at_head(struct doubly_linked_list *head, int data)
{
    struct doubly_linked_list *new_node = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
    new_node->val = data;
    if (head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }

    else
    {
        struct doubly_linked_list *tail = head->prev;
        new_node->val = data;
        new_node->next = head;
        new_node->prev = tail;
        tail->next = new_node;
        head->prev = new_node;
        return new_node;
    }
}

void display(struct doubly_linked_list *head)
{
    if (head == NULL)
    {
        printf("empty list");
    }
    else
    {
        struct doubly_linked_list *temp = head;
        do
        {
            printf("%d : %p\n", temp->val, temp->next);
            temp = temp->prev;
        } while (temp != head);
    }
}

int main()
{
    int a, b, c;
    struct doubly_linked_list *head = NULL;
    head = insert_at_head(head, 10);
    head = insert_at_head(head, 20);
    head = insert_at_head(head, 30);
    head = insert_at_head(head, 40);
    head = insert_at_head(head, 50);
    display(head);

    return 0;
}