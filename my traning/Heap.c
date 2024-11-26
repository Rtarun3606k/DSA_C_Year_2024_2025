#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 20

typedef struct heap
{
    int heap[20];
    int heapsize;
} NODE;

void init(NODE *h)
{
    h->heapsize = 0;
    h->heap[0] = INT_MAX;
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void topDowApproach(NODE *h, int data) // or also insert
{
    int c, p;
    h->heap[++(h->heapsize)] = data; // Insert at the end
    c = h->heapsize;
    p = c / 2;

    while (h->heap[p] < h->heap[c])
    {
        swap(&h->heap[p], &h->heap[c]);
        c = p;
        p = c / 2;
    }
}

void display(NODE *h)
{
    if (h->heapsize > 0)
    {
        for (int i = 1; i <= h->heapsize; i++)
        {
            printf("%d ", h->heap[i]);
            printf("\n");
        }
    }
}

void deleteElement(NODE *h)
{
    int d, c, p;
    d = h->heap[1];
    h->heap[1] = h->heap[h->heapsize--];
    p = 1;
    c = 2 * p;

    while (c <= h->heapsize)
    {
        if (c + 1 <= h->heapsize && h->heap[c + 1] > h->heap[c])
        {
            c++;
        }
        if (h->heap[p] < h->heap[c])
        {
            swap(&h->heap[p], &h->heap[c]);
        }
        else
        {
            break;
        }
        p = c;
        c = 2 * p;
    }
}

int main()
{
    int a, b, c;
    NODE *h1, *h2;
    h1 = (NODE *)malloc(sizeof(NODE));
    init(h1);
    topDowApproach(h1, 10);
    topDowApproach(h1, 11);
    topDowApproach(h1, 12);
    topDowApproach(h1, 16);
    display(h1);
    deleteElement(h1);
    printf("\nAfter deletion\n");
    display(h1);

    return 0;
}