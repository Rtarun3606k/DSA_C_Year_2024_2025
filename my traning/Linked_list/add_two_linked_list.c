#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}

struct Node *insert_at_begining(struct Node *head, int ele)
{
    if (head == NULL)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = ele;
        new_node->link = NULL;
        head = new_node;
        return head;
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = ele;
        new_node->link = head;
        head = new_node;
        return head;
    }
}

struct Node *inserting_at_end(struct Node *head, int ele)
{
    if (head == NULL)
    {
        printf("List was empty creating a new node  at head!\n");
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = head;
        new_node->data = ele;
        new_node->link = NULL;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
        return head;
    }
}

void print_reverse(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        head = insert_at_begining(head, head->data);
        print_reverse(head->link);
        printf("%d\t", head->data);
    }
}

int main()
{
    int a, b, c;
    struct Node *head = NULL;
    struct Node *head2 = NULL;
    head2 = insert_at_begining(head2, 10);
    head = insert_at_begining(head, 10);
    head = insert_at_begining(head, 20);
    head = insert_at_begining(head, 30);
    head = inserting_at_end(head, 30);
    display(head);
    printf("\nprinting in revese order : ");
    print_reverse(head);

    return 0;
}