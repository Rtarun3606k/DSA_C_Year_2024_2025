#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to check if two subtrees are mirrors of each other
bool isMirror(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;

    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

// Main function to check if the tree is symmetric recursively
bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}

// Function to print a boolean result
void printResult(bool result)
{
    if (result)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}

int main()
{
    // Test Case 1: Symmetric Tree
    struct TreeNode *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);

    printf("Test Case 1: ");
    printResult(isSymmetric(root1));

    // Test Case 2: Non-Symmetric Tree
    struct TreeNode *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);

    printf("Test Case 2: ");
    printResult(isSymmetric(root2));

    return 0;
}