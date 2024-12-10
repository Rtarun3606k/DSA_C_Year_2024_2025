#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct LinkedListStacks
{
    int data;
    struct LinkedListStacks *next;
};

typedef struct LinkedListStacks Stack;

Stack *push(Stack *s, int data)
{
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->data = data;
    if (s == NULL)
    {
        return newNode;
    }

    newNode->next = s;
    return newNode;
}

Stack *pop(Stack *s)
{
    if (s == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    else
    {

        Stack *temp = s;
        s = temp->next;
        free(temp);
        return s;
    }
}

void display(Stack *s)
{
    if (s == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        Stack *temp = s;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int a, b, c;

    Stack *s = NULL;
    printf("Enter the number of elements you want to push: ");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter the element you want to push: ");
        scanf("%d", &b);
        s = push(s, b);
    }
    display(s);
    s = pop(s);
    display(s);

    return 0;
}