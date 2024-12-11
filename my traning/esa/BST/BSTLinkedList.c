#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct BSTLinkedList
{
    int data;
    struct BSTLinkedList *left;
    struct BSTLinkedList *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->left, data);
        }
        return root;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int search(Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (data > root->data)
        {
            return search(root->right, data);
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        if (root->data == data)
        {
            return 1;
        }
    }
    return 0;
}

int minium(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        if (root->left == NULL)
        {
            return root->data;
        }
        else
        {
            minium(root->left);
        }
    }
}

int maximum(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        if (root->right == NULL)
        {
            return root->data;
        }
        else
        {
            maximum(root->right);
        }
    }
}

Node *deleteNode(Node *root, int data)
{
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else if (root == NULL)
    {
        return root;
    }
    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else
        {
            Node *temp = createNode(minium(root->right));
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    int a, b, c;
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        /* code */
        root = insert(root, i * 2);
    }
    for (int i = 10; i >= 5; i--)
    {
        root = insert(root, i * 3);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("postOrder: ");
    postorder(root);
    printf("\n");
    printf("preOrder: ");
    preorder(root);
    printf("\n");
    printf("seached: %d\n", search(root, 6));
    root = deleteNode(root, 6);
    root = deleteNode(root, 0);
    printf("Inorder: ");
    inorder(root);

    return 0;
}