#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node
{
    int info;
    struct node *next;
} NODE;

// Function prototypes
NODE *getNode(int ele);
NODE *createList(NODE *head, int ele);
void display(NODE *head);
NODE *concat(NODE *head1, NODE *head2);
void freeList(NODE *head);

// Function to create a new node with given data
NODE *getNode(int ele)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->next = NULL;
    return newNode;
}

// Function to create and append a node to the linked list
NODE *createList(NODE *head, int ele)
{
    NODE *newNode = getNode(ele);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        NODE *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to concatenate two lists alternately
NODE *concat(NODE *head1, NODE *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    NODE *newHead = head1;
    NODE *p = head1;
    NODE *q = head2;
    NODE *pNext, *qNext;

    while (p != NULL && q != NULL)
    {
        pNext = p->next;
        qNext = q->next;

        p->next = q;
        if (pNext == NULL)
        {
            break;
        }
        q->next = pNext;

        p = pNext;
        q = qNext;
    }

    if (q != NULL)
    {
        // Append remaining nodes of q to the end of p
        if (p != NULL)
        {
            p->next = q;
        }
        else
        {
            newHead = q;
        }
    }

    return newHead;
}

// Function to display the linked list
void display(NODE *head)
{
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated to the list
void freeList(NODE *head)
{
    NODE *p = head;
    NODE *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}

int main()
{
    NODE *head1 = NULL;
    NODE *head2 = NULL;
    int ele, n;

    // Input the first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        head1 = createList(head1, ele);
    }

    // Input the second list
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        head2 = createList(head2, ele);
    }

    // Concatenate the lists alternately
    NODE *head3 = concat(head1, head2);

    // Display the resulting list
    display(head3);

    // Free the memory allocated to all lists
    freeList(head3);

    return 0;
}
