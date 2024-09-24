#include <stdio.h>
#include <stdlib.h>

int isempty(int top)
{
    return top == -1;
}

int isfull(int top, int size)
{
    return top == size - 1;
}

void push(int *top, int data, int *arr, int size)
{
    if (isfull(*top, size))
    {
        printf("Stack is full\n");
    }
    else
    {
        (*top)++;
        arr[*top] = data;
    }
}

void pop(int *top, int *arr)
{
    if (isempty(*top))
    {
        printf("Stack is empty\n");
    }
    else
    {
        (*top)--;
    }
}

int main()
{
    int top = -1;
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        push(&top, i, arr, size);
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
    return 0;
}
