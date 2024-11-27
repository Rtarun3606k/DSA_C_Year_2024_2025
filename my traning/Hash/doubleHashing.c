#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int key;
    char data;
} HashTable;

void init(HashTable *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        ht[i].key = 0;
        ht[i].data = 0;
    }
}

void insert(HashTable *ht, int data)
{
    int i = 0;
    int hash2 = 7 - (data % 7);
    int hash = ((data % MAX) + 1 * hash2) % MAX;
    while (ht[hash].key != 0 && i < MAX)
    {
        i++;
        hash = ((data % MAX) + i * hash2) % MAX;
    }
    if (ht[hash].key == 0)
    {
        ht[hash].key = 1;
        ht[hash].data = data;
    }
    else
    {
        printf("Data cannot be inserted\n");
    }
}

void search(HashTable *ht, int data)
{
    int hash, i = 0, hash2;
    hash2 = 7 - (data % 7);
    hash = ((data % MAX) + i * hash2) % MAX;
    while (i < MAX)
    {
        if (ht[hash].data == data && ht[hash].key == 1)
        {
            printf("Data found at index %d %d\n", hash, ht[hash].data);
            return;
        }
        i++;
        hash = ((data % MAX) + i) % MAX;
    }
    printf("Data not found\n");
}

// Display hash table content
void display(HashTable *hashTable)
{
    printf("\nHash Table:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (hashTable[i].key == 1)
        {
            printf("Index %d: %d\n", i, hashTable[i].data);
        }
        else
        {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}

int main()
{
    int a, b, c;
    HashTable ht[MAX];
    init(ht);

    return 0;
}