#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// list format frokm tree to list
// when we have a tree we can represent it in a list format by using an array and the following formula
// from the root node = 1
// leftchild  = 2i
// rightchild = 2i+1
// parent = i/2

//        A
//    B      C
// d   E   F   G

// A B C D E F G
// 1 2 3 4 5 6 7
#define MAX_SIZE 100

struct BinaryTree
{
    int data[MAX_SIZE];
    int lastNodeIndex;
};

void initiliseBinaryTree(struct BinaryTree *tree)
{
    tree->lastNodeIndex = 0;
}

void insertData(struct BinaryTree *tree, int data)
{
    if (tree->lastNodeIndex == MAX_SIZE)
    {
        printf("Tree is full\n");
        return;
    }

    tree->data[++tree->lastNodeIndex] = data;
    return;
}

void PrintTree(struct BinaryTree *tree)
{
    for (int i = 0; i < tree->lastNodeIndex; i++)
    {
        printf("%d ", tree->data[i]);
    }
}

// Main function
int main()
{
    struct BinaryTree tree;
    initiliseBinaryTree(&tree);

    insertData(&tree, 1);
    insertData(&tree, 2);
    insertData(&tree, 3);
    insertData(&tree, 4);
    insertData(&tree, 5);

    PrintTree(&tree);

    return 0;
}