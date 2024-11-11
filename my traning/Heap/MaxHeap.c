#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct heap
{
    int heap[20];
    int heapsize;
} NODE;

void maxHeapify(NODE *H, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;

    if (left < H->heapsize && H->heap[left] > H->heap[max])
    {
        max = left;
    }
    if (right < H->heapsize && H->heap[right] > H->heap[max])
    {
        max = right;
    }

    if (max != index)
    {
        int temp = H->heap[max];
        H->heap[max] = H->heap[index];
        H->heap[index] = temp;
        maxHeapify(H, max);
    }
}

void createHeap(NODE *H, int arr[], int size)
{

    H->heapsize = size;
    int i;
    for (i = 0; i < size; i++)
    {
        H->heap[i] = arr[i];
    }
    i = (H->heapsize - 2) / 2;

    while (i >= 0)
    {
        maxHeapify(H, i);
        i--;
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
    int a, b, c;
    int arr[7] = {10, 20, 15, 12, 40, 25, 18};
    NODE H;
    createHeap(&H, arr, 7);
    printHeap(&H);

    return 0;
}