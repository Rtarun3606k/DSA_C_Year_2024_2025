#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct heap
{
    int heap[20];
    int heapsize;
} Heap;

void Heapify(Heap *h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;

    if (left < h->heapsize && h->heap[left] > h->heap[index])
    {
        max = left;
    }
    if (right < h->heapsize && h->heap[right] > h->heap[index])
    {
        max = right;
    }
    if (max != index)
    {
        int temp = h->heap[max];
        h->heap[max] - h->heap[index];
        h->heap[index] = temp;
        Heapify(h, max);
    }
}

void createArray(Heap *h, int arr[], int size)
{

    h->heapsize = size;
    int i;
    for (i = 0; i < size; i++)
    {
        h->heap[i] = arr[i];
    }
    i = (h->heapsize - 2) / 2;

    while (i >= 0)
    {
        Heapify(h, i);
        i--;
    }
}

void printHeap(Heap *h)
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
    Heap h;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    createArray(&h, arr, 9);
    Heapify(&h, 0);
    printHeap(&h);

    return 0;
}