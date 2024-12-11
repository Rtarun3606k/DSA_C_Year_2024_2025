#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct DoubleHashing
{
    int data;
    int flag;
} HashTable;

void init(HashTable *ht)
{
    for (int i = 0; i < 10; i++)
    {
        ht[i].data = 0;
        ht[i].flag = 0;
    }
}

void insert(HashTable *hash, int data)
{
    int i = 0;
    int hash2 = 7 - (data % MAX);
    int hash1 = ((data % MAX) + i * hash2) % MAX;
    while (hash[hash1].flag == 1 && i < MAX)
    {
        i++;
        hash1 = ((data % MAX) + i * hash2) % MAX;
    }
    if (hash[hash1].flag == 0)
    {
        hash[hash1].data = data;
        hash[hash1].flag = 1;
    }
    else
    {
        printf("Data cannot be inserted\n");
    }
}

void search(HashTable *hash, int data)
{
    int i = 0;
    int hash2 = 7 - (data % MAX);
    int hash1 = ((data % MAX) + i * hash2) % MAX;
    for (int i = 0; i < MAX; i++)
    {
        if (hash[hash1].data == data && hash[hash1].flag == 1)
        {
            printf("Data found at index %d %d\n", hash1, hash[hash1].data);
            return;
        }
        else
        {
            hash1 = ((data % MAX) + i * hash2) % MAX;
        }
    }
    printf("Data not found\n");
}

void display(HashTable *hash)
{
    for (int i = 0; i < MAX; i++)
    {
        if (hash[i].flag == 1)
        {
            printf("Index: %d Data: %d\n", i, hash[i].data);
        }
        else
        {
            printf("Index: %d Data: Empty\n", i);
        }
    }
}

int main()
{
    int a, b, c;
    HashTable hash[MAX];
    init(hash);
    insert(hash, 10);
    insert(hash, 22);
    insert(hash, 33);
    display(hash);
    search(hash, 22);

    return 0;
}