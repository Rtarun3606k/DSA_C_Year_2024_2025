#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
    int row;
    int col;
};

struct Node *create_node(int data, int row, int col, struct Node *head)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = data;
    new_node->row = row;
    new_node->col = col;
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
        while (temp != NULL)
        {
            printf("data : %d\t row : %d\t col : %d\t \n", temp->val, temp->row, temp->col);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    struct Node *head = NULL;
    int sparse_matrix[4][5] = {{0, 0, 2, 0, 0}, {3, 0, 0, 0, 4}, {0, 0, 0, 0, 0}, {0, 0, 6, 0, 0}};
    for (int i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {

                head = create_node(sparse_matrix[i][j], i, j, head);
            }
        }
    }
    display(head);
    // display(sparse_matrix);

    return 0;
}