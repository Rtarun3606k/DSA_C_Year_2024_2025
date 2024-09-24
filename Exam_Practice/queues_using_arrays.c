#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isFull(int size, int *r)
{
    if (*r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(int *r, int *f)
{
    if (*r == *f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(int arr[], int data, int size, int *r)
{
    if (isFull(size, r))
    {
        printf("queue is full\n");
    }
    else
    {
        (*r)++;
        arr[*r] = data;
    }
}

void dnque(int arr[], int size, int *f, int *r)
{
    if (isEmpty(r, f))
    {
        printf("queue is empty\n");
    }
    else
    {
        (*f)++;
        printf("Dequeued: %d\n", arr[*f]);
    }
}

int main()
{
    int f, r, size;
    size = 10;
    int arr[size];
    f = r = -1;
    for (int i = 0; i < size; i++)
    {
        enque(arr, i, size, &r);
    }
    dnque(arr, size, &f, &r);
    dnque(arr, size, &f, &r);
    dnque(arr, size, &f, &r);
    for (int i = f + 1; i < r; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}