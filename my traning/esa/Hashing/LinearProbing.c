#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct LinearProbing
{
    int data;
    int flag; // 0 empty 1 filled

} Hash;

void init(Hash *hash)
{
    for (int i = 0; i < SIZE; i++)
    {
        hash[i].flag = hash[i].data = 0;
    }
}

void insert(Hash *hash, int data)
{
    int i = 0;
    int hashIndex = ((data % SIZE) + 1) % SIZE;
    for (int i = 0; i < SIZE && hash[hashIndex].flag == 0; i++)
    {
        hashIndex = ((data % SIZE) + 1) % SIZE;
    }
    if (hash[hashIndex].flag == 0)
    {
        hash[hashIndex].data = data;
        hash[hashIndex].flag = 1;
        printf("Data inserted at index %d\n", hashIndex);
    }
    else
    {
        printf("Data cannot be inserted\n");
    }
}

void search(Hash *hash, int data)
{
    int i = 0;
    int hashIndex = ((data % SIZE) + 1) % SIZE;
    for (int i = 0; i < SIZE; i++)
    {
        if (hash[hashIndex].data == data && hash[hashIndex].flag == 1)
        {
            printf("Data found at index %d %d\n", hashIndex, hash[hashIndex].data);
            return;
        }
        else
        {
            hashIndex = ((data % SIZE) + 1) % SIZE;
        }
    }
    printf("Data not found\n");
}

int main()
{
    int a, b, c;
    Hash hash[SIZE];
    init(hash);
    insert(hash, 10);
    insert(hash, 22);
    insert(hash, 33);
    insert(hash, 46);
    insert(hash, 54);
    search(hash, 22);
    search(hash, 30);
    search(hash, 46);

    return 0;
}