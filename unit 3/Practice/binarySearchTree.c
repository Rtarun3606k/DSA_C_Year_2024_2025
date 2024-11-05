#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    char side;
};

typedef struct node TreeNode;

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d,%c ], ", root->data, root->side);
        inorder(root->right);
    }
}
TreeNode *insert(TreeNode **root, int data)
{
    if (*root == NULL)
    {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        if (*root == NULL)
        {
            printf("Memory allocation failed\n");
            return NULL;
        }

        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = data;
        (*root)->side = 'r'; // Root node side is 'r'
        return *root;
    }
    else if (data > (*root)->data)
    {
        TreeNode *rightChild = insert(&(*root)->right, data);
        rightChild->side = 'r'; // Right child side is 'r'
        (*root)->right = rightChild;
    }
    else if (data < (*root)->data)
    {
        TreeNode *leftChild = insert(&(*root)->left, data);
        leftChild->side = 'l'; // Left child side is 'l'
        (*root)->left = leftChild;
    }
    else
    {
        printf("Duplicate data\n");
    }
    return *root;
}

bool searchTreeNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return false;
    }
    else if (data == root->data)
    {
        printf("Data found\n");
        return true;
    }
    else if (data > root->data)
    {
        return searchTreeNode(root->right, data);
    }
    else if (data < root->data)
    {
        return searchTreeNode(root->left, data);
    }
    else
    {
        printf("Data not found\n");
        return false;
    }
}

int main()
{
    int a, b, c;
    TreeNode *root = NULL;
    for (int i = 10; i > 5; i--)
    {
        root = insert(&root, i * 3);
        /* code */
    }

    // root->left = insert(root->left, 5);
    // root->right = insert(root->right, 15);
    // root->left->left = insert(root->left->left, 3);
    // root->left->right = insert(root->left->right, 7);

    printf("Root: %d\n", root->data);
    inorder(root);

    return 0;
}