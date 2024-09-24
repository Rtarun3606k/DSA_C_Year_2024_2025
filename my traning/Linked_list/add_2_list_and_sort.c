#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insert(struct ListNode *head, int data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        struct ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        // new_node->next = NULL;
        return head;
    }
}

void diaplay(struct ListNode *head)
{
    if (head == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nthe list is : ");
        struct ListNode *temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->val);
            temp = temp->next;
        }
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

void put_in_arr(int arr[], int size, struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *temp1 = list1;
    struct ListNode *temp2 = list2;
    int count1 = 0;
    while (temp1 != NULL)
    {
        arr[count1] = temp1->val;
        temp1 = temp1->next;
        count1++;
    }
    while (temp2 != NULL)
    {
        arr[count1] = temp2->val;
        temp2 = temp2->next;
        count1++;
    }
}

struct ListNode *insert_in_node(struct ListNode *head, int arr[], int size)
{
    struct ListNode *temp = head;
    for (int i = 0; i < size; i++)
    {
        int data = arr[i];
        temp = insert(head, data);
    }
    return head;
}

int main()
{
    int arr[50], b, c;
    struct ListNode *head = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *head3 = NULL;
    for (int i = 0; i < 6; i++)
    {
        int evalute = (i + 1) * 30;
        int evalute2 = (i + 1) * 25;
        head = insert(head, evalute);
        head2 = insert(head2, evalute2);
    }
    diaplay(head);
    diaplay(head2);
    put_in_arr(arr, 5, head, head2);
    bubbleSort(arr, 5);
    head3 = insert_in_node(head3, arr, 5);
    diaplay(head3);

    return 0;
}