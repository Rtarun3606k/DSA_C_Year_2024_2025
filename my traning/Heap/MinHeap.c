#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct heap
{
    int heap[20];
    int heapsize;
} NODE;

void MinHeapify(NODE *h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;

    if (left < h->heapsize && h->heap[left] < h->heap[min])
    {
        min = left;
    }

    if (right < h->heapsize && h->heap[right] < h->heap[min])
    {
        min = right;
    }

    if (min != index)
    {
        int temp = h->heap[min];
        h->heap[min] = h->heap[index];
        h->heap[index] = temp;
        MinHeapify(h, min);
    }
}

void createHeap(NODE *h, int arr[], int size)
{
    h->heapsize = size;
    int i;
    for (i = 0; i < h->heapsize; i++)
    {
        h->heap[i] = arr[i];
    }
    for (i = (h->heapsize - 2) / 2; i >= 0; i--)
    {
        MinHeapify(h, i);
    }
}

void printHeap(NODE *h)
{
    for (int i = 0; i < h->heapsize; i++)
    {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {100, 20, 15, 40, 50, 100, 25, 45, 10};
    NODE h;
    createHeap(&h, arr, 9);
    printHeap(&h);

    return 0;
}
