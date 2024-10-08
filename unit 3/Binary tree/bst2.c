#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *getSucessor(node *n)
{
    node *current = n;

    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

node *deNode(node *root, int x)
{

    if (root == NULL)
    {
        return root;
    }

    if (x < root->data)
    {
        root->left = deNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = getSucessor(root->right);

        root->data = temp->data;

        root->right = deNode(root->right, temp->data);
    }

    return root;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

node *insert(node *root, int x)
{
    if (root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }

    return root;
}

int main()
{
    int a, b, c;
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inOrder(root);
    printf("\n");
    root = deNode(root, 20);
    inOrder(root);
    printf("\n");
    root = deNode(root, 70);
    inOrder(root);

    return 0;
}