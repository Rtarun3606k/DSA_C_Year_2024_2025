#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct HeightOfBinarySearchTree
{
    int data;
    struct HeightOfBinarySearchTree *left;
    struct HeightOfBinarySearchTree *right;
    // char side;
};

typedef struct HeightOfBinarySearchTree BST;

BST *insert(BST *root, int data)
{
    if (root == NULL)
    {
        BST *newNode = (BST *)malloc(sizeof(BST));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
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
    printf("[%d ,] ", root->data);
    inorder(root->right);
}

int heightOfBST(BST *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = heightOfBST(root->left);
    int rightHeight = heightOfBST(root->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
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
    root = insert(root, 5);
    root = insert(root, 2);
    inorder(root);
    printf("\n");
    printf("Height of the tree is %d\n", heightOfBST(root));

    return 0;
}