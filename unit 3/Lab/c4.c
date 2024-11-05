#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a TreeNode
struct TreeNode
{
    char title[101];
    char author[101];
    char isbn[21];
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new TreeNode
struct TreeNode *createNode(char *title, char *author, char *isbn)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    strcpy(newNode->isbn, isbn);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a book into the BST
struct TreeNode *insertNode(struct TreeNode *root, char *title, char *author, char *isbn)
{
    if (root == NULL)
    {
        return createNode(title, author, isbn);
    }

    if (strcmp(isbn, root->isbn) < 0)
    {
        root->left = insertNode(root->left, title, author, isbn);
    }
    else if (strcmp(isbn, root->isbn) > 0)
    {
        root->right = insertNode(root->right, title, author, isbn);
    }

    return root;
}

// Function to search for a book in the BST
struct TreeNode *searchBook(struct TreeNode *root, char *isbn)
{
    if (root == NULL || strcmp(root->isbn, isbn) == 0)
    {
        return root;
    }

    if (strcmp(isbn, root->isbn) < 0)
    {
        return searchBook(root->left, isbn);
    }
    else
    {
        return searchBook(root->right, isbn);
    }
}

int main()
{
    int n;
    scanf("%d\n", &n); // Read number of books and consume the newline
    struct TreeNode *root = NULL;
    char line[256]; // To read each line of book details
    char title[101], author[101], isbn[21];

    // Input books
    for (int i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%100[^,],%100[^,],%20s", title, author, isbn); // Parse title, author, and isbn
        root = insertNode(root, title, author, isbn);
    }

    // Input ISBN query and search for the book
    fgets(isbn, sizeof(isbn), stdin);
    strtok(isbn, "\n"); // Remove newline character
    struct TreeNode *result = searchBook(root, isbn);

    if (result != NULL)
    {
        printf("%s, %s, %s\n", result->title, result->author, result->isbn);
    }
    else
    {
        printf("Book not found\n");
    }

    return 0;
}