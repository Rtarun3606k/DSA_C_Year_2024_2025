#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct
{
    int count;
    Node *head;
} HashMap;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error creating a new node.\n");
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashMap *createHashMap()
{
    HashMap *hashMap = (HashMap *)malloc(sizeof(HashMap));
    hashMap->count = 0;
    hashMap->head = (Node *)malloc(SIZE * sizeof(Node));
    for (int i = 0; i < SIZE; i++)
    {
        hashMap->head[i].value = -1;
        hashMap->head[i].next = NULL;
    }
    return hashMap;
}

void insert(HashMap *hashMap, int value)
{
    int key = value % SIZE;
    Node *newNode = createNode(value);
    if (hashMap->head[key].value == -1)
    {
        hashMap->head[key].value = value;
    }
    else
    {
        Node *temp = &hashMap->head[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    hashMap->count++;
}

void search(HashMap *hashMap, int value)
{
    int key = value % SIZE;
    Node *temp = &hashMap->head[key];
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            printf("Element found: %d\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found: %d\n", value);
}

void display(HashMap *hashMap)
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *temp = &hashMap->head[i];
        while (temp != NULL)
        {
            if (temp->value != -1)
            {
                printf("%d ", temp->value);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void delete(HashMap *hashMap, int value)
{
    int key = value % SIZE;
    Node *temp = &hashMap->head[key];
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            if (prev == NULL)
            {
                hashMap->head[key].value = -1;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            hashMap->count--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element not found: %d\n", value);
}

int main()
{
    int a, b, c;
    HashMap *hashMap = createHashMap();
    while (1)
    {
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &b);
            insert(hashMap, b);
            break;
        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &b);
            search(hashMap, b);
            break;
        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &b);
            delete (hashMap, b);
            break;
        case 4:
            display(hashMap);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}