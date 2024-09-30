#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};
typedef struct Node node;

node *insert_node(int data, node *root)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;

    if (root == NULL)
    {
        root = new_node;
        return root;
    }

    if (root->data > data)
    {
        root->left = insert_node(data, root->left);
    }
    else if (root->data < data)
    {
        root->right = insert_node(data, root->right);
    }
    else
    {
        printf("Duplicate data\n");
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int a, b, c;
    node *root = NULL;
    while (1)
    {
        printf("Enter 1 to insert, 2 to display, 3 to exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter data to insert\n");
            scanf("%d", &b);
            root = insert_node(b, root);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid input\n");
        }
    }

    return 0;
}