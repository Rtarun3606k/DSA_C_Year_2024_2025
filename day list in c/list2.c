#include <stdio.h>
#include "list1.h"
int main()
{
    int choice, ele, status;
    ARLST al, *pal;
    pal = &al;
    printf("1. Append\n2. Delete Last\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1:
            display(pal);
            printf("Enter the element to append: ");
            scanf("%d", &ele);
            status = append(pal, ele);
            statusTeller(status);
            if (status == 0)
            {
                break;
            }

        case 2:
            display(pal);
            status = deleteLast(pal, &ele);
            statusTeller(status);
            if (status == 0)
                printf("Deleted element: %d\n", ele);
            break;

        case 3:

            display(pal);
            break;
        case 4:
            return 0;

        default:
            break;
        }
        // printf("1. Append\n2. Delete Last\n3. Exit\n");
        printf("1. Append\n2. Delete Last\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
    } while (choice < 4);

    return 0;
}

void initlist(ARLST *l)
{
    l->last = -1;
}

int append(ARLST *l, int ele)
{
    if ((l)->last == MAX - 1)
    {
        printf("List is full\n");
        return 0;
    }
    (l)->last++;
    (l)->a[(l)->last] = ele;
    return 1;
}

int deleteLast(ARLST *l, int *ele)
{
    if ((l)->last == -1)
    {
        printf("List is empty\n");
        return 0;
    }
    *ele = (l)->a[(l)->last];
    (l)->last--;
    return 1;
}

void display(ARLST *l)
{
    int i;
    printf("displaying list\n");
    if ((l)->last == -1)
    {
        printf("List is empty\n");
        return;
    }
    for (i = 0; i < (l)->last; i++)
    {
        printf("%d\t", (l)->a[i]);
    }
    printf("\n");
}

void statusTeller(int status)
{
    if (status == 1)
        printf("Success\n");
    else
    {
        printf("Failure\n");
        // break;
    }
}