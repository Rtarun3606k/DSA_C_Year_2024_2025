#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct DeletionBST
{
    int data;
    struct DeletionBST *left;
    struct DeletionBST *right;
    // char side;
};

typedef struct DeletionBST BST;

BST *insert(BST *root, int data)
{
    if (root == NULL)
    {
        BST *newNode = (BST *)malloc(sizeof(BST));
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
        // root->right = insert(root->right, data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
        /* code */
    }
    return root;
}

void inorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("[%d] ", root->data);
    inorder(root->right);
}

BST *inorderPredecessor(BST *root)
{
    BST *current = root;
    while (current && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

BST *deletion(BST *root, int data)
{
    BST *temp;
    if (root == NULL)
    {
        printf("Data not found\n");
        return root;
    }
    if (data < root->data)
    {
        root->left = deletion(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        temp = inorderPredecessor(root->left);
        root->data = temp->data;
        root->left = deletion(root->left, temp->data);
    }
    return root;
}

int main()
{
    int a, b, c;
    BST *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 6);
    inorder(root);
    printf("\n");
    deletion(root, 10);
    inorder(root);

    return 0;
}