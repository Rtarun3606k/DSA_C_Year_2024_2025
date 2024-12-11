#include <stdio.h>
#include <stdlib.h>

typedef struct HeapTopDownApproch
{
    int heap[20];
    int heapSize;
} Heap;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Heap *h, int data)
{
    int child, parent;
    h->heap[++(h->heapSize)] = data;
    child = h->heapSize;
    parent = child / 2;
    while (parent > 0 && h->heap[parent] < h->heap[child])
    {
        swap(&h->heap[parent], &h->heap[child]);
        child = parent;
        parent = child / 2;
    }
}

void delete(Heap *h)
{
    int child, parent;
    if (h->heapSize == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    h->heap[1] = h->heap[h->heapSize--];
    parent = 1;
    child = 2 * parent;

    while (child <= h->heapSize)
    {
        if (child + 1 <= h->heapSize && h->heap[child] < h->heap[child + 1])
        {
            child++;
        }
        if (h->heap[parent] < h->heap[child])
        {
            swap(&h->heap[parent], &h->heap[child]);
            parent = child;
            child = 2 * parent;
        }
        else
        {
            break;
        }
    }
}

void display(Heap *h)
{
    for (int i = 1; i <= h->heapSize; i++)
    {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}

int main()
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->heapSize = 0;

    insert(h, 1);
    insert(h, 2);
    insert(h, 3);
    insert(h, 4);
    insert(h, 5);
    insert(h, 6);
    insert(h, 7);

    printf("After Insertion\n");
    display(h);

    delete (h);
    delete (h);

    printf("After deletion\n");
    display(h);

    free(h);

    return 0;
}