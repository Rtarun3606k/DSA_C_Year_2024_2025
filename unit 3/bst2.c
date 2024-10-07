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

int main()
{
    int a, b, c;
    node *root = NULL;
    node *temp = NULL;
    node *sucessor = NULL;

    return 0;
}