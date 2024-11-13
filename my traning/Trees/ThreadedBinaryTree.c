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

Tree *insertNode(Tree *root, int data)
{
    Tree *temp = root;
    Tree *parent = NULL;
    if (root == NULL)
    {
        return createNode(data);
    }
    while (temp != NULL)
    {
        parent = temp;
        if (data < temp->data)
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
        else if (temp->data < data)
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

        else
        {
            printf("duplicate data\n");
            return root;
        }
    }

    if (data > parent->data)
    {
        Tree *newNode = createNode(data);
        newNode->right = parent->right;
        newNode->rThreaded = parent->rThreaded;
        newNode->left = parent;
        parent->right = newNode;
        parent->rThreaded = 0;
    }
    else
    {
        Tree *newNode = createNode(data);
        newNode->left = parent->left;
        newNode->lThreaded = parent->lThreaded;
        newNode->right = parent;
        parent->left = newNode;
        parent->lThreaded = 0;
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
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 30);
    root = insertNode(root, 12);
    inorderTraversal(root);

    return 0;
}