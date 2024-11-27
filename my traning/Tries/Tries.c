#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    Trie *children[255];
    int eos;
} Trie;

typedef struct
{
    Trie *node;
    int index;
} STACK;

char output[255];
int len = 0, top = -1;
STACK *Stack[30];

void push(Trie *t, int index)
{
    STACK *nn = (STACK *)malloc(sizeof(STACK));
    nn->node = t;
    nn->index = index;
    Stack[++top] = nn;
}

int pop()
{
    return Stack[top--];
}

int childCount(Trie *t)
{
    int count = 0;
    for (int i = 0; i < 256; i++)
    {
        if (t->children[i] != NULL)
        {
            count++;
        }
    }
    return count;
}

Trie *createNode()
{
    Trie *nn = (Trie *)malloc(sizeof(Trie));
    for (int i = 0; i < 256; i++)
    {
        nn->children[i] = NULL;
    }
    nn->eos = 0;

    return nn;
}

void insertWord(Trie *root, char *word)
{
    int index;
    Trie *temp = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i];
        if (temp->children[index] == NULL)
        {
            temp->children[index] = createNode();
        }

        temp = temp->children[i];
    }
    temp->eos = 1;
}

void display(Trie *root)
{
    Trie *t = root;
    for (int i = 0; i < 255; i++) // Traverse all possible children for each character
    {
        if (t->children[i] != NULL) // If a child node exists
        {
            output[len++] = i;            // Add character to output array (current word)
            if (t->children[i]->eos == 1) // If this node marks the end of a word, print the word
            {
                printf("\n");
                for (int j = 0; j < len; j++)
                    printf("%c", output[j]);
            }
            display(t->children[i]); // Recursively display words starting from this node
        }
    }
    len--; // Backtrack to previous character after traversing child nodes
    return;
}

void search(Trie *root, char *word)
{
    Trie *temp = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i];
        if (temp->children[i] == NULL)
        {
            printf("Word not found\n");
            return;
        }
        temp = temp->children[i];
    }
    if (temp->eos == 1)
    {
        printf("Word found\n");
    }
    else
    {
        printf("Word not found\n");
    }
}

void deleteData(Trie *root, char *word)
{
    int index;
    STACK *s;
    Trie *temp = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i];
        if (temp->children[index] == NULL)
        {
            printf("Word not found\n");
            return;
        }
        push(temp, index);
        temp = temp->children[index];
    }
    temp->eos = 0;
    if (childCount(temp) >= 1)
    {
        return;
    }

    else // If no children, backtrack and delete nodes
    {
        s = pop(); // Get last visited node and index
        temp = s->node;
        index = s->index;
        while (childCount(temp) <= 1 && temp->eos == 0) // Delete nodes until a branch or another word is encountered
        {
            free(temp->children[index]);  // Free the child node
            temp->children[index] = NULL; // Set pointer to NULL to remove reference
            s = pop();                    // Move back to the previous node and repeat if necessary
            temp = s->node;
            index = s->index;
        }
    }
}
int main()
{
    int a, b, c;

    return 0;
}