#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct ThreadedBinaryTree
{
    int data;
    int rThreaded;
    int lThreaded;
    struct ThreadedBinaryTree *right;
    struct ThreadedBinaryTree *left;
};

typedef struct ThreadedBinaryTree Tree;

Tree *createNode(int data)
{
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->rThreaded = 1;
    newNode->lThreaded = 1;
    return newNode;
}

Tree *insertData(Tree *root, int data)
{
    Tree *parent = NULL;
    Tree *temp = root;

    if (root == NULL)
    {
        return createNode(data);
    }

    while (temp)
    {
        parent = temp;
        if (temp->data == data)
        {
            printf("Duplicate data\n");
            return root;
        }
        if (temp->data > data)
        {
            if (temp->lThreaded == 0)
            {
                temp = temp->left;
            }
            else
            {
                break;
            }
        }
        if (temp->data < data)
        {
            if (temp->rThreaded == 0)
            {
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
    }
    if (parent->data > data)
    {
        Tree *newNode = (Tree *)malloc(sizeof(Tree));
        newNode->right = parent->right;
        newNode->rThreaded = parent->rThreaded;
        newNode->left = parent;
        parent->right = newNode;
        parent->rThreaded = 0;
    }
    else
    {
        Tree *newNode = (Tree *)malloc(sizeof(Tree));
        newNode->left = parent->left;
        newNode->lThreaded = parent->lThreaded;
        parent->lThreaded = 0;
        newNode->right = parent;
        parent->left = newNode;
    }
    return root;
}

Tree *inorderSuccessor(Tree *t)
{
    if (t->rThreaded == 1)
        return t->right;

    t = t->right;
    while (t->lThreaded == 0)
        t = t->left;

    return t;
}

void inorderTraversal(Tree *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return;
    }

    // Go to the leftmost node
    Tree *t = root;
    while (t->lThreaded == 0)
        t = t->left;

    // Traverse the tree using threads
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = inorderSuccessor(t);
    }
}

int main()
{
    int a, b, c;
    Tree *root = NULL;
    while (1)
    {
        printf("1. Insert Data\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &b);
            root = insertData(root, b);
            break;
        case 2:
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}