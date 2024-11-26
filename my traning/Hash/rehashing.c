#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int key;
    char data;
} NODE;

typedef struct
{
    int size;
    NODE *table;
} HashTable;

int count = 0;

HashTable *init(int size)
{
    HashTable *hash = (HashTable *)malloc(sizeof(HashTable));
    hash->size = size;
    hash->table = (NODE *)malloc(sizeof(NODE) * size);
    for (int i = 0; i < size; i++)
    {
        hash->table[i].key = 0;
    }
    return hash;
}

void destroyHash(HashTable *ht)
{
    free(ht->table);
    free(ht);
}

void rehash(HashTable **ht, int data)
{
    int newSize = (*ht)->size * 2;
    HashTable *newHash = init(newSize);
    for (int i = 0; i < (*ht)->size; i++)
    {
        int hash, j = 0;
        hash = ((*ht)->table[i].data % newSize + j) % newSize;
        while (newHash->table[hash].key != 0 && j < newSize)
        {
            j++;
            hash = ((*ht)->table[i].data % newSize + j) % newSize;
        }
        newHash->table[hash].key = 1;
        newHash->table[hash].data = (*ht)->table[i].data;
    }
    destroyHash(*ht);
    *ht = newHash;
}

void insert(HashTable *ht, int data)
{
    int hash, i = 0;

    count++;
    if (count > (float)(0.75 * ht->size))
    {
        rehash(&ht, data);
    }
    else
    {
        hash = ((data % ht->size) + i) % ht->size;
        while (ht->table[hash].key != 0 && i < ht->size)
        {
            i++;
            hash = ((data % ht->size) + i) % ht->size;
        }
        if (ht->table[hash].key == 0)
        {
            ht->table[hash].key = 1;
            ht->table[hash].data = data;
            printf("Data inserted at index %d\n", hash);
        }
        else
        {
            printf("Data cannot be inserted\n");
        }
    }
}

void search(HashTable *ht, int data)
{
    int hash, i = 0;
    hash = ((data % MAX) + i) % MAX;
    while (i < MAX)
    {
        if (ht->table[hash].data == data && ht->table[hash].key == 1)
        {
            printf("Data found at index %d %d\n", hash, ht->table[hash].data);
            return;
        }
        i++;
        hash = ((data % MAX) + i) % MAX;
    }
    printf("Data not found\n");
}

void display(HashTable *ht)
{
    int hash, i = 0;
    // hash = ((data % MAX) + i) % MAX;
    for (i = 0; i < MAX; i++)
    {
        if (ht->table[i].key == 1)
        {
            /* code */
            printf("%d %d\n", ht->table[i].key, ht->table[i].data);
        }
    }
}

int main()
{
    int a, b, c;
    HashTable *ht = init(MAX);
    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 40);
    insert(ht, 50);
    insert(ht, 60);
    insert(ht, 70);
    display(ht);
    printf("\n");
    search(ht, 20);
    search(ht, 30);
    search(ht, 40);
    display(ht);
    printf("\n");

    return 0;
}