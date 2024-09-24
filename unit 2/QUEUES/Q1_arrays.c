#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int qinsert(int *, int *, int *, int, int);
int qdelete(int *, int *, int *);
void display(int *, int *, int *);

int main()
{
    int a, b, c;
    int *q;
    int ch, k, x;
    int f, r, size;
    f = r = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    q = (int *)malloc(size * sizeof(int));
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            k = qinsert(q, &f, &r, size, x);
            if (k == -1)
            {
                printf("Queue is full\n");
            }
            break;
        case 2:
            k = qdelete(q, &f, &r);
            if (k == -1)
            {
                printf("Queue is empty\n");
            }
            break;
        case 3:
            display(q, &f, &r);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}
int qinsert(int *q, int *f, int *r, int size, int x)
{
    if (*r == size - 1)
    {
        printf("Queue is full or Overflow\n");
        return -1;
    }
    (*r)++;
    q[*r] = x;
    if (*f == -1)
    {
        *f = 0;
    }
    return 0;
}

int qdelete(int *q, int *f, int *r)
{
    if (*f == -1)
    {
        return -1;
    }
    printf("Element deleted is %d\n", q[*f]);
    if (*f == *r)
    {
        *f = *r = -1;
    }
    else
    {
        (*f)++;
    }
    return 0;
}

void display(int *q, int *f, int *r)
{
    int i;
    if (*f == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of the queue are: ");
    for (i = *f; i <= *r; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}