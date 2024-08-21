#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node *inser_after_an_element(struct Node *head, int ele, int after);
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

// print linked list in reverse manner
void print_reverse(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    print_reverse(head->link);
    printf("%d ", head->data);
}

// concatinate 2 linked list

// insert at position
struct Node *insert_at_position(struct Node *head, int ele, int pos)
{
    if (pos >= 0)
    {
        struct Node *new_node = create_node(head, ele);
        struct Node *temp = head;
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->link;
            count++;
        }
        new_node->link = temp->link;
        temp->link = new_node;
        return head;
    }
    else
    {
        printf("\nInvalid position\n");
        return head;
    }
}

struct Node *delete_at_begining(struct Node *head)
{
    if (head == NULL)

    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        struct Node *temp = head;
        head = head->link;
        free(temp);
        return head;
    }
}

struct Node *delete_at_end(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
        return head;
    }
}

struct Node *delete_at_position(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = temp;
            temp = temp->link;

            count++;
        }
        prev->link = temp->link;
        free(temp);
        return head;
    }
}

bool search_in_linked_list(struct Node *head, int ele)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            return true;
        }
        temp = temp->link;
    }
    return false;
}

int main()
{
    int a, b, c;
    struct Node *head = NULL;
    head = create_node(head, 10);
    head->link = create_node(head->link, 20);
    head->link->link = create_node(head->link, 30);

    display(head);
    head = insert_at_beginning(head, 5);
    printf("inserted at begining\n");
    display(head);
    head = insert_at_end(head, 40);
    printf("inserted at end\n");
    display(head);
    printf("print linked list in reverse manner\n");
    print_reverse(head);
    head = insert_at_position(head, 25, 3);
    display(head);
    print_reverse(head);
    printf("\ninsert after an element : ");
    head = inser_after_an_element(head, 35, 5);
    display(head);
    printf("deleting  element from the begining");
    head = delete_at_begining(head);
    display(head);
    head = delete_at_end(head);
    display(head);
    printf("enter an element to be searched : ");
    scanf("%d", &a);
    if (search_in_linked_list(head, a))
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
// qn : insert a node in a linked list after some data value
// qn :perform arthematic operation on 2 linked lists and store it in 3rd linked list
// qn : create  a linked list and delete alternate nodes from it
// qn : create a linked list and delete all the nodes which have a greater value on right side

struct Node *inser_after_an_element(struct Node *head, int ele, int after)
{

    int count_of_nodes = 1;
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nlist is : ");
        while (temp != NULL)
        {
            if (temp->data == after)
            {
                struct Node *new_node = create_node(head, ele);
                new_node = insert_at_position(head, ele, count_of_nodes + 1);

                return head;
            }

            printf("%d ", temp->data);
            count_of_nodes++;
            temp = temp->link;
        }
    }
}
