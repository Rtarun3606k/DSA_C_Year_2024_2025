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
    int hash, i = 0;
    hash = ((data % MAX) + i) % MAX;

    while (ht[hash].key != 0 && i < MAX)
    {
        i++;
        hash = ((data % MAX) + i) % MAX;
    }
    if (ht[hash].key == 0)
    {
        ht[hash].key = 1;
        ht[hash].data = data;
        printf("Data inserted at index %d\n", hash);
    }
    else
    {
        printf("Data cannot be inserted\n");
    }
}

void search(HashTable *ht, int data)
{
    int hash, i = 0;
    hash = ((data % MAX) + i) % MAX;
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

void display(HashTable *ht)
{
    int hash, i = 0;
    // hash = ((data % MAX) + i) % MAX;
    for (i = 0; i < MAX; i++)
    {
        if (ht[i].key == 1)
        {
            /* code */
            printf("%d %d\n", ht[i].key, ht[i].data);
        }
    }
}

int main()
{
    int a, b, c;
    HashTable ht[MAX];
    init(ht);
    while (1)
    {
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter data to insert\n");
            scanf("%d", &b);
            insert(ht, b);
            break;
        case 2:
            printf("Enter data to search\n");
            scanf("%d", &c);
            search(ht, c);
            break;
        case 3:
            printf("Displaying Hash Table\n");
            display(ht);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}