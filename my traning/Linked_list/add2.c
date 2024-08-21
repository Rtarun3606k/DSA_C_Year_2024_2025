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
    new_node->next = NULL;

    if (head == NULL)
    {

        return new_node;
    }
    else
    {

        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        // new_node->next = NULL;
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
        while (head != NULL)
        {
            printf("%d ", head->val);
            head = head->next;
        }
    }
    printf("\n"); // Ensure output ends with a newline
}

struct Node *add2Lists(struct Node *l1, struct Node *l2)
{
    struct Node *result_list = NULL;
    struct Node *tail_result_list = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->val = sum;
        new_node->next = NULL;

        if (result_list == NULL)
        {
            result_list = new_node;
            tail_result_list = new_node;
        }
        else
        {
            tail_result_list->next = new_node;
            tail_result_list = new_node;
        }
    }
    return result_list;
}

int main()
{
    int a, b, c;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    head1 = insert(head1, 2);
    head1 = insert(head1, 4);
    head1 = insert(head1, 3);
    head2 = insert(head2, 5);
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);
    display(head1);
    printf("\n");
    display(head2);
    head3 = add2Lists(head1, head2);
    display(head3);
    return 0;
}