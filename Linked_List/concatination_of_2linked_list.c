#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *create_node(struct Node *head, int ele)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = ele;
    new_node->link = NULL;
    return new_node;
}

void display(struct Node *head)
{
    int count_of_nodes = 0;
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
            count_of_nodes++;
            temp = temp->link;
        }
    }
    printf("\nNumber of nodes in the list = %d\n", count_of_nodes);
}

struct Node *insert_at_beginning(struct Node *head, int ele)
{

    if (head == NULL)
    {
        head = create_node(head, ele);
        return head;
    }
    else
    {
        struct Node *new_node;
        new_node = create_node(head, ele);
        new_node->link = head;
        head = new_node;
        return head;
    }
}

struct Node *insert_at_end(struct Node *head, int ele)
{
    {
        if (head == NULL)
        {
            head = create_node(head, ele);
            return head;
            /* code */
        }
        else
        {
            struct Node *new_node = head;
            while (new_node->link != NULL)
            {
                new_node = new_node->link;
            }
            new_node->link = create_node(new_node->link, ele);
            return head;
        }
    }
}

struct Node *concatinate_2_linked_list(struct Node *head1, struct Node *head2, struct Node *head3)
{
    // if (head1 == NULL)
    // {
    //     return head2;
    // }
    // if (head2 == NULL)
    // {
    //     return head1;
    // }

    struct Node *temp = head1;
    // struct Node *temp2 = head1;
    while (temp->link != NULL)
    {

        temp = temp->link;
        // printf("temp->data = %d\n", temp->data);
    }
    temp->link = head2;
    return head1;
}

int main()
{
    int a, b, c;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    head1 = insert_at_beginning(head1, 10);
    head1 = insert_at_end(head1, 20);
    head1 = insert_at_end(head1, 30);
    head1 = insert_at_end(head1, 40);
    display(head1);
    head2 = insert_at_beginning(head2, 50);
    head2 = insert_at_end(head2, 60);
    head2 = insert_at_end(head2, 70);
    head2 = insert_at_end(head2, 80);
    display(head2);
    head3 = concatinate_2_linked_list(head1, head2, head3);
    display(head3);
    display(head1);

    return 0;
}

// perform polynomial addition usong single addition