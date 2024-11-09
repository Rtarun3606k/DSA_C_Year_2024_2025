#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct InsertionBinarySerchTree
{
    int data;
    struct InsertionBinarySerchTree *left;
    struct InsertionBinarySerchTree *right;
    char side;
};

typedef struct InsertionBinarySerchTree BST;

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

BST *InsertData(BST *root, int data)
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
        root->left = InsertData(root->left, data);
        root->left->side = 'l';
    }
    else if (data > root->data)
    {
        root->right = InsertData(root->right, data);
        root->right->side = 'r';
    }
    if (root->data == data)
    {
        printf("%d data is already present by insertion\n", root->data);
        return root;
    }
    return root;
}

void SerchData(BST *root, int data)
{
    if (root == NULL)
    {
        printf("the data is not present in the tree\n");
        return;
    }
    if (root->data == data)
    {
        printf("%d data is present in the tree\n", data);
        return;
    }
    else if (data < root->data)
    {
        return SerchData(root->left, data);
    }
    else
    {
        return SerchData(root->right, data);
    }
}

BST *NEWNODE(int data)
{
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST *Insert(BST *root, int data)
{
    BST *prev = NULL;
    BST *originalRoot = root;
    if (root == NULL)
    {
        return InsertData(root, data);
    }
    while (root != NULL)
    {
        prev = root;
        if (root->data < data)
        {
            root = root->right;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            printf("%d data is already present by insertion\n", root->data);
            return originalRoot;
        }
    }
    if (prev->data < data)
    {
        prev->right = InsertData(prev->right, data);
        prev->right->side = 'r';
    }
    else
    {
        prev->left = InsertData(prev->left, data);
        prev->left->side = 'l';
    }
    return originalRoot;
}

int main()
{
    int a, b, c;
    BST *root = NULL;
    BST *root2 = NULL;
    root = InsertData(root, 10);
    root = InsertData(root, 20);
    root = InsertData(root, 5);
    root = InsertData(root, 15);
    root = InsertData(root, 30);
    printTree(root);
    printf("\n");
    root2 = InsertData(root2, 60);
    for (int i = 0; i < 5; i++)
    {
        root2 = InsertData(root2, i * 2);
    }
    printTree(root2);
    printf("\n");
    SerchData(root, 4);
    root = Insert(root, 5);
    root = Insert(root, 50);
    root = Insert(root, 25);
    SerchData(root2, 2);
    SerchData(root2, 4);
    printf("\n");
    Insert(root, 5);
    Insert(root, 50);
    Insert(root, 25);
    printTree(root);

    return 0;
}

// no repetaion allowed in the tree
// the data is already present
// [5, l] [10, r] [15, l] [20, r] [30, r]
