#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct MyArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *a, int used_size, int total_size)
{
    a->total_size = total_size;
    a->ptr = malloc(total_size * sizeof(int));
    a->used_size = used_size;
}

void show(struct MyArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (*a).ptr[i]);
    }
}

int main()
{
    struct MyArray a;
    int b, c;
    createArray(&a, 10, 20);
    show(&a);
    return 0;
}