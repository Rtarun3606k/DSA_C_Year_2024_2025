#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct element_t
{
    int data;
    int pty;
} typedef element_t;

void pqinsert(element_t *pq, int x, int pty, int *count)
{
    int j;
    element_t temp;
    temp.data = x;
    temp.pty = pty;
    j = *count - 1;
    while ((j >= 0) && (pq[j].pty > temp.pty))
    {
        pq[j + 1] = pq[j];
        j--;
    }
    pq[j + 1] = temp;
    (*count)++;
}

element_t pqdelete(element_t *pq, int *count)
{
    int i;
    element_t temp;
    if (*count == 0)
    {
        printf("Queue is empty\n");
        temp.data = -1;
        temp.pty = -1;
    }
    else
    {
        temp = pq[0];
        for (i = 0; i < *count; i++)
        {
            pq[i - 1] = pq[i];
        }
    }
    (*count)--;
    return temp;
}

void display(element_t *pq, int count)
{
    int i;
    if (count == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            printf("%d(%d) ", pq[i].data, pq[i].pty);
        }
        printf("\n");
    }
}

int main()
{
    int a, b, c;
    element_t pq[10], temp;
    int count = 0;
    int choose;
    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &a, &b);
            pqinsert(pq, a, b, &count);
            break;
        case 2:
            pqdelete(pq, &count);
            break;
        case 3:
            display(pq, count);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choose != 4);
    display(pq, count);

    return 0;
}