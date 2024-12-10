#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

struct BSTArray
{
    int data;
    int flag;
};

typedef struct BSTArray Node;

void *insert(int data, Node *bst, int index)
{
    if (bst[index].flag == 0)
    {
        bst[index].data = data;
        bst[index].flag = 1;
    }
    else if (bst[index].flag == 1)
    {
        printf("Index is already occupied\n");
    }
    else if (data > bst[index].data)
    {
        insert(data, bst, index * 2 + 2);
    }
    else if (data < bst[index].data)
    {
        insert(data, bst, index * 2 + 1);
    }
    else
    {
        printf("some error occured");
    }
}

void inorder(Node *bst, int index)
{
    if (bst[index].flag == 1 & index < MAX)
    {
        inorder(bst, index * 2 + 1);
        printf("%d ", bst[index].data);
        inorder(bst, index * 2 + 2);
    }
}

int main()
{
    int a, b, c;
    Node bst[MAX];
    for (a = 0; a < MAX; a++)
    {
        bst[a].flag = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        /* code */
        insert(10 * i, bst, i);
    }

    inorder(bst, 0);
    inorder(bst, 0);

    return 0;
}