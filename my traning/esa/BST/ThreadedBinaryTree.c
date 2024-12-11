#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct threadedBinarytree
{
    int data;
    int rThreded;
    int lThreded;
    struct threadedBinarytree *right;
    struct threadedBinarytree *left;
} Tree;

Tree *creteNode(int data)
{
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    newNode->data = data;
    newNode->rThreded = 1;
    newNode->lThreded = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree *insertData(Tree *root, int data)
{
    if (root == NULL)
    {
        return creteNode(data);
    }
    Tree *temp = root;
    Tree *parent = NULL;

    while (temp != NULL)
    {
        parent = temp;
        if (data > temp->data)
        {
            if (temp->rThreded == 0)
            {
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
        else if (data < temp->data)
        {
            if (temp->lThreded == 0)
            {
                temp = temp->left;
            }
            else
            {
                /* code */
                break;
            }
        }
        else
        {
            printf("Duplicate data\n");
            return root;
        }
    }
    if (parent->data > data)
    {
        Tree *newNode = creteNode(data);
        newNode->right = parent->right;
        newNode->rThreded = parent->rThreded;
        newNode->left = parent;
        parent->right = newNode;
        parent->rThreded = 0;
    }
    else
    {

        Tree *newNode = creteNode(data);
        newNode->left = parent->left;
        newNode->lThreded = parent->lThreded;
        parent->lThreded = 0;
        newNode->right = parent;
        parent->left = newNode;
    }
    return root;
}

Tree *inorderSucessor(Tree *root)
{
    if (root->rThreded == 1)
    {
        return root->right;
    }

    root = root->right;
    while (root->lThreded == 0)
    {
        root = root->left;
    }
    return root;
}

void inorderTraversal(Tree *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    Tree *temp = root;
    while (temp->lThreded == 0)
    {
        temp = temp->left;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = inorderSucessor(temp);
    }
}

int main()
{
    int a, b, c;
    Tree *root = NULL;
    while (1)
    {
        printf("1. Insert\n2. Inorder Traversal\n3. Exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &b);
            root = insertData(root, b);
            break;
        case 2:
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}