#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct HashNode
{
    int data;
    struct HashNode *next;
} HashNode;

HashNode *head[MAX] = {NULL}, *c;

void insert(int data)
{
    int hash = data % MAX;
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->data = data;
    newNode->next = NULL;
    if (head[hash] == NULL)
    {
        head[hash] = newNode;
    }
    else
    {
        c = head[hash];
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = newNode;
    }
}

void search(int data)
{
    int hash = data % MAX;
    c = head[hash];
    while (c != NULL)
    {
        if (c->data == data)
        {
            printf("Data found\n");
            return;
        }
        c = c->next;
    }
    printf("Data not found\n");
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        c = head[i];
        while (c != NULL)
        {
            printf("%d %d\n", c->data, i);
            c = c->next;
        }
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(23);
    insert(45);
    insert(60);
    insert(70);
    display();

    return 0;
}
