#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct binarySearchTree
{
    int data;
    struct binarySearchTree *left;
    struct binarySearchTree *right;
    char side;
};

typedef struct binarySearchTree BST;

void printTree(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("[%d, %c] ", root->data, root->side);
    printTree(root->right);
}

BST *insertData(BST *root, int data)
{
    if (root == NULL)
    {
        BST *newNode = (BST *)malloc(sizeof(BST));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->side = 'r';
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insertData(root->left, data);
        root->left->side = 'l';
    }
    else if (data > root->data)
    {
        root->right = insertData(root->right, data);
        root->right->side = 'r';
    }
    else
    {
        printf("the data is already present\n");
    }
    return root;
}

void SearchTree(BST *root, int data)
{
    if (root == NULL)
    {
        printf("the data is not present in the tree\n");
        return;
    }
    else if (root->data == data)
    {
        printf("%d data is present in the tree wing %c\n", root->data, root->side);
        return;
    }
    else if (data < root->data)
    {
        SearchTree(root->left, data);
    }
    else
    {
        SearchTree(root->right, data);
    }
}

void inorder(BST *root)
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
    BST *root = NULL;
    root = insertData(root, 21);
    for (int i = 0; i < 5; i++)
    {
        root = insertData(root, i * 2);
    }
    printTree(root);
    printf("\n");
    SearchTree(root, 4);
    SearchTree(root, 10);
    SearchTree(root, 21);
    SearchTree(root, 6);

    return 0;
}