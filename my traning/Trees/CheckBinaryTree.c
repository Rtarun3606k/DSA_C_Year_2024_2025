#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
        // return true;
    }
    printTree(root->left);
    printf("[%d, %c] ", root->data, root->side);
    printTree(root->right);
}

BST *Insertdata(BST *root, int data)
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
    else if (data <= root->data)
    {
        root->left = Insertdata(root->left, data);
        root->left->side = 'l';
    }
    else if (data >= root->data)
    {
        root->right = Insertdata(root->right, data);
        root->right->side = 'r';
    }
    else
    {
        printf("The data is already present\n");
    }
    return root;
}

void SearchTree(BST *root, int data)
{
    if (root == NULL)
    {
        printf("The data is not present in the tree\n");
        return;
    }
    if (root->data == data)
    {
        printf("The data is present in the tree\n");
        return;
    }
    else if (data <= root->data)
    {

        return SearchTree(root->left, data);
    }
    else
    {
        return SearchTree(root->right, data);
    }
}

bool isBST(BST *root)
{
    static BST *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return true;
    }
}

int main()
{
    int a, b, c;
    BST *root = NULL;
    BST *root2 = NULL;
    root = Insertdata(root, 10);
    root = Insertdata(root, 20);
    root = Insertdata(root, 5);
    root = Insertdata(root, 15);
    root = Insertdata(root, 30);
    root = Insertdata(root, 2);
    printTree(root);
    printf("\n");
    root2 = Insertdata(root2, 60);
    root2 = Insertdata(root2, 20);
    root2 = Insertdata(root2, 5);
    root2 = Insertdata(root2, 15);
    root2 = Insertdata(root2, 30);
    root2 = Insertdata(root2, 2);
    printTree(root2);

    if (isBST(root))
    {
        printf("\nIt is a binary search tree\n");
    }
    else
    {
        printf("\nIt is not a binary search tree\n");
    }

    if (isBST(root2))
    {
        printf("\nIt is a binary search tree\n");
    }
    else
    {
        printf("\nIt is not a binary search tree\n");
    }
    SearchTree(root, 10);
    SearchTree(root, 5);
    SearchTree(root, 20);

    SearchTree(root2, 10);
    SearchTree(root2, 60);
    SearchTree(root2, 20);

    return 0;
}

// Output:          10
//                /    \
//               5      20
//              /      /  \
//             2       15   30

// It is a binary search tree

// It is not a binary search tree :
// Output:          60
//                /
//               20
//              /
//             5
//              \
//               15
//                \
//                 30
//                  /
//                 2
