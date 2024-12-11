#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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
    for (int i = 0; i < hash->size; i++)
    {
        hash->table[i].key = 0;
    }
    return hash;
}

void destroyTable(HashTable *table)
{
    free(table->table);
    free(table);
}

void reash(HashTable **ht, int data)
{
    int newSize = (*ht)->size * 2;
    HashTable *newhash = init(newSize);
    for (int i = 0; i < (*ht)->size; i++)
    {
        int hash, j = 0;
        hash = (((*ht)->table[i].data % newSize) + j) % newSize;
        while (newhash->table[hash].key != 0 && j < newSize)
        {
            j++;
            hash = (((*ht)->table[i].data % newSize) + j) % newSize;
        }
        newhash->table[hash].key = 1;
        newhash->table[hash].data = (*ht)->table[i].data;
    }
    destroyHash(*ht);
    *ht = newhash;
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
        hash = ((data % ht->size) + 1) % ht->size;
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
    hash = ((data % ht->size) + i) % ht->size;
    while (ht->table[hash].data != data && i < ht->size)
    {
        i++;
        hash = ((data % ht->size) + i) % ht->size;
    }
    if (ht->table[hash].data == data)
    {
        printf("Data found at index %d\n", hash);
    }
    else
    {
        printf("Data not found\n");
    }
}

void display(HashTable *ht)
{
    int hash, i = 0;
    for (i = 0; i < ht->size; i++)
    {
        if (ht->table[i].key == 1)
        {
            printf("%d %d\n", ht->table[i].key, ht->table[i].data);
        }
    }
}

int main()
{
    int a, b, c;

    return 0;
}