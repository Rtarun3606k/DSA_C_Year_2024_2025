#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct DeletionBinaryTree
{
    int data;
    struct DeletionBinaryTree *left;
    struct DeletionBinaryTree *right;
    char side;
};

typedef struct DeletionBinaryTree BST;

BST *Insertion(BST *root, int data)
{
    if (root == NULL)
    {
        BST *newNode = (BST *)malloc(sizeof(BST));
        newNode->data = data;
        newNode->left = NULL;
        newNode->side = 'r';
        return newNode;
    }
    else if (data > root->data)
    {
        root->right = Insertion(root->right, data);
        root->right->side = 'r';
    }
    else if (data < root->data)
    {
        root->left = Insertion(root->left, data);
        root->left->side = 'l';
    }
    else
    {
        printf("%d data is already present by insertion\n", root->data);
        return root;
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
    printf("[%d, %c] ", root->data, root->side);
    inorder(root->right);
}

BST *inorderPredessor(BST *root)
{
    BST *current = root;
    while (current && current->right != NULL)
    {

        current = current->right;
    }
    return current;
}

int SearchBinaryTree(BST *root, int data)
{
    if (root == NULL)
    {
        printf("Data not found\n");
        return 0;
    }
    if (root->data == data)
    {
        printf("Data found\n");
        return 1;
    }
    else if (data < root->data)
    {
        return SearchBinaryTree(root->left, data);
    }
    else
    {
        return SearchBinaryTree(root->right, data);
    }
}

BST *DeletNode(BST *root, int data)
{

    BST *inorderPredessorValue = NULL;
    if (root == NULL)
    {
        printf("Data not found\n");
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    else if (data < root->data)
    {
        root->left = DeletNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = DeletNode(root->right, data);
    }
    else
    {
        inorderPredessorValue = inorderPredessor(root->left);
        root->data = inorderPredessorValue->data;
        root->left = DeletNode(root->left, inorderPredessorValue->data);
    }
    return root;
}

int main()
{
    int a, b, c;
    BST *root = NULL;
    root = Insertion(root, 10);
    root = Insertion(root, 20);
    root = Insertion(root, 30);
    root = Insertion(root, 40);
    root = Insertion(root, 50);
    root = Insertion(root, 5);
    root = Insertion(root, 4);
    root = Insertion(root, 3);
    inorder(root);
    printf("\n");
    DeletNode(root, 10);
    inorder(root);
    printf("\n");
    DeletNode(root, 3);
    inorder(root);
    printf("\n");
    DeletNode(root, 50);
    inorder(root);
    printf("\n");
    DeletNode(root, 0);
    inorder(root);
    printf("\n");

    return 0;
}

// Output: [3, l] [4, l] [5, l] [10, r] [20, r] [30, r] [40, r] [50, r]

//     10
//     /\
//    5  20
//    /   \
//    4    30
//     \     \
//      3     40
//              /
//               50