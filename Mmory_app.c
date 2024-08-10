#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int *a, b, *c;
    a = (int *)malloc(sizeof(int));
    *a = 10;
    printf("the value of a is :%d\n", *a);
    printf("the address of a is :%x\n", a);
    b = 5;
    c = (int *)malloc(b * sizeof(int));
    for (int i = 0; i < b; i++)
    {
        if (/* condition */ c == NULL)
        {
            /* code */
            printf("memory is not allocated\n");
        }
        else
        {
            printf("the value of :%d\n", *(c + i));
        }
    }
    for (int i = 0; i < b; i++)
    {
        printf("the value of :%d\n", i);
        scanf("%d", c + i);
    }
    for (int i = 0; i < b; i++)
    {
        printf("the value after initilazation :%d\n", *(c + i));
    }
    printf("enter the value time to extend the memory is :\n");
    scanf("%d", &b);
    c = (int *)realloc(c, b * sizeof(int));
    for (int i = 0; i < b; i++)
    {
        if (/* condition */ c == NULL)
        {
            /* code */
            printf("memory is not allocated\n");
        }
        else
        {
            printf("the value of :%d\n", *(c + i));
        }
    }
    printf("end of ALL");
    free(a);
    free(c);
    for (int i = 0; i < b; i++)
    {
        if (/* condition */ c == NULL)
        {
            /* code */
            printf("memory is not allocated\n");
        }
        else
        {
            printf("the value of :%d\n", *(c + i));
        }
    }
    return 0;
}
