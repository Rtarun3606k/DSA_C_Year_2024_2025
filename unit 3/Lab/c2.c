#include <stdio.h>
#include <stdlib.h>

// Structure to store priority and processing time
typedef struct
{
    int priority;
    int time;
} Task;

// Function to swap two tasks
void swap(Task *a, Task *b)
{
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at node i
void heapify(Task arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && (arr[left].priority > arr[largest].priority ||
                     (arr[left].priority == arr[largest].priority && arr[left].time > arr[largest].time)))
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && (arr[right].priority > arr[largest].priority ||
                      (arr[right].priority == arr[largest].priority && arr[right].time > arr[largest].time)))
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to implement heap sort
void heapSort(Task arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call min heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Task *arr = (Task *)malloc(n * sizeof(Task));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].priority, &arr[i].time);
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d)\n", arr[i].priority, arr[i].time);
    }

    free(arr);
    return 0;
}
