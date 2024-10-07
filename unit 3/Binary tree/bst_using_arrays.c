#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

struct Node
{
    int data;
    int flag;
};

typedef struct Node node;

void insert(node *root, int data, int index)
{
    if (root[index].flag == 0 && index < SIZE)
    {
        root[index].data = data;
        root[index].flag = 1;
    }
    else if (root[index].data > data)
    {
        insert(root, data, 2 * index + 1);
    }
    else if (root[index].data < data)
    {
        insert(root, data, 2 * index + 2);
    }
    else
    {
        printf("Duplicate data\n");
    }
}

void view_inorder(node *root, int index)
{
    if (index >= SIZE)
    {
        return;
    }
    if (root[index].flag == 0)
    {
        return;
    }
    view_inorder(root, 2 * index + 1); // Visit left subtree
    printf("%d ", root[index].data);   // Print data
    view_inorder(root, 2 * index + 2); // Visit right subtree
}

int main()
{
    node root[SIZE] = {0};
    insert(root, 50, 0);
    insert(root, 30, 0);
    insert(root, 70, 0);
    insert(root, 20, 0);
    insert(root, 40, 0);
    insert(root, 60, 0);
    insert(root, 80, 0);

    printf("In-order traversal: ");
    view_inorder(root, 0);
    printf("\n");

    return 0;
}
