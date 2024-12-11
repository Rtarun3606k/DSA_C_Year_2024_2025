#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int heap[20];
    int heapsize;
} NODE;

void heapify(NODE *h, int index)
{
    int right = index * 2 + 2;
    int left = index * 2 + 1;
    int max = index;
    if (left < h->heapsize && h->heap[left] > h->heap[max])
    {
        max = left;
    }
    if (right < h->heapsize && h->heap[right] > h->heap[max])
    {
        max = right;
    }
    if (max != index)
    {
        int temp = h->heap[max];
        h->heap[max] = h->heap[index];
        h->heap[index] = temp;
        heapify(h, max);
    }
}

void createHeap(NODE *h, int arr[], int size)
{
    h->heapsize = size;
    for (int i = 0; i < size; i++)
    {
        h->heap[i] = arr[i];
    }
    for (int i = (h->heapsize - 2) / 2; i >= 0; i--)
    {
        heapify(h, i);
    }
}

void display(NODE *h)
{
    for (int i = 0; i < h->heapsize; i++)
    {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}

int main()
{
    NODE *h = (NODE *)malloc(sizeof(NODE));
    int arr[] = {1, 2, 3, 4, 5, 6, 21, 8, 9};
    createHeap(h, arr, 9);
    display(h);

    free(h);
    return 0;
}