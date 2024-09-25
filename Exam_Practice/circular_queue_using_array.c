#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isEmpty(int *f, int *r)
{
    if (*f == -1 && *r == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    printf("Queue is not empty\n");
    return 0;
}

int isFull(int *f, int *r, int SIZE)
{
    if (*f == (*r + 1) % SIZE)
    {
        printf("Queue is full\n");
        return 1;
    }
    printf("Queue is not full\n");
    return 0;
}

void display(int *f, int *r, int size, int arr[])
{
    if (isEmpty(f, r))
    {
        return;
    }

    printf("\n");
    int i = *f;
    while (1)
    {
        printf("%d ", arr[i]);

        if (i == *r)
        {
            break;
        }

        i = (i + 1) % size;
    }
}

void enqueue(int *f, int *r, int size, int arr[], int data)
{
    if (isFull(f, r, size))
    {
        return;
    }
    if (*f == -1)
    {
        *f = 0;
    }

    *r = (*r + 1) % size;
    arr[*r] = data;
    printf("enqued element is %d\n", data);
}

void dequeue(int *f, int *r, int arr[], int size)
{
    if (isEmpty(f, r))
    {
        return;
    }
    if (*f == *r)
    {
        *f = *r = -1;
    }
    else
    {
        printf("Dequeued element is %d\n", arr[*f]);
        *f = (*f + 1) % size;
    }
}

int main()
{
    int f, r, size;
    size = 5;
    f = r = -1;
    int *arr = (int *)malloc(size * sizeof(int));
    enqueue(&f, &r, size, arr, 1);
    enqueue(&f, &r, size, arr, 3);
    enqueue(&f, &r, size, arr, 2);
    display(&f, &r, size, arr);
    dequeue(&f, &r, arr, size);
    display(&f, &r, size, arr);
    return 0;
}