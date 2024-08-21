#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// stack using arrays
// fixed size arr
// top pointer
// push : add element to the top
// pop : remove element from the top
// peek : get the top element
// display : display all elements

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

struct stack *push(struct stack *ptr, int data)
{
    if (isempty(ptr))
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
    return ptr;
}

void display(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("Element %d: %d\n", i + 1, ptr->arr[i]);
    }
}

int main()
{
    int data;
    struct stack *stack_var;
    stack_var->size = 3;
    stack_var->top = -1;
    stack_var->arr = (int *)malloc(stack_var->size * sizeof(int));
    if (isempty(stack_var))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the data to push to the stack: ");
        scanf("%d", &data);
        stack_var = push(stack_var, data);
    }
    display(stack_var);

    return 0;
}