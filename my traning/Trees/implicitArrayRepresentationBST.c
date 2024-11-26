#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct implicitArrayRepresentationBST
{
    int data;
    int used;
    /* data */
};

typedef struct implicitArrayRepresentationBST ImplictArrayBST;

void init(ImplictArrayBST arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].used = 0;
    }
}

void insert(ImplictArrayBST *bst)
{
    int p = 0;
    while (p < 0 && bst[p].used)
    {
        if (bst[p].data < bst->data)
        // If the current node's data is less than the root node's data,
        // move to the right child in the array representation.
        {
            p = 2 * p + 2;
        }
        else
        {
            // If the current node's data is greater than or equal to the root node's data,
            // move to the left child in the array representation.
            p = 2 * p + 1;
        }
    }
}

void inorder(ImplictArrayBST *bst, int r)
{
    if (r < 0 || bst[r].used == 0)
    {
        return;
    }
    inorder(bst, 2 * r + 1);
    printf("%d \n", bst[r].data);
    inorder(bst, 2 * r + 2);
}

int main()
{
    int a, b, c;
    ImplictArrayBST bst[100];
    init(bst, 100);
    insert(bst);
    for (int i = 0; i < 5; i++)
    {
        bst[i].data = i * 2;
        bst[i].used = 1;
    }
    inorder(bst, 0);

    return 0;
}