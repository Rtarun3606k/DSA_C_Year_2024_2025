#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node TreeNode;

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        if (root == NULL)
        {
            printf("Memory allocation failed\n");
        }

        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        printf("Duplicate data\n");
    }
}

int main()
{
    int a, b, c;
    TreeNode *root = NULL;
    root = insert(root, 10);
    root->left = insert(root->left, 5);
    root->right = insert(root->right, 15);
    root->left->left = insert(root->left->left, 3);
    root->left->right = insert(root->left->right, 7);

    printf("Root: %d\n", root->data);
    inorder(root);

    return 0;
}