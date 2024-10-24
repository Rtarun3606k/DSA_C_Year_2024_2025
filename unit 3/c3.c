#include <stdio.h>
#include <stdlib.h>

// Structure to store a meeting with start and end times
typedef struct
{
    int start;
    int end;
} Meeting;

// Function to compare two meetings by their start times
int compareMeetings(const void *a, const void *b)
{
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the min-heap
void heapify(int *heap, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Function to insert an element into the min-heap
void insertHeap(int *heap, int *heapSize, int value)
{
    heap[*heapSize] = value;
    int i = *heapSize;
    (*heapSize)++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the min-heap
int extractMin(int *heap, int *heapSize)
{
    if (*heapSize <= 0)
        return -1;

    if (*heapSize == 1)
    {
        (*heapSize)--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[*heapSize - 1];
    (*heapSize)--;
    heapify(heap, *heapSize, 0);

    return root;
}

// Function to find the minimum number of rooms required
int minMeetingRooms(Meeting meetings[], int n)
{
    if (n == 0)
        return 0;

    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    // Min-heap to keep track of end times of meetings
    int *minHeap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;

    // Add the end time of the first meeting
    insertHeap(minHeap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++)
    {
        // If the current meeting starts after the earliest ending meeting, reuse the room
        if (meetings[i].start >= minHeap[0])
        {
            extractMin(minHeap, &heapSize);
        }

        // Add the current meeting's end time to the heap
        insertHeap(minHeap, &heapSize, meetings[i].end);
    }

    int result = heapSize;
    free(minHeap);
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int rooms = minMeetingRooms(meetings, n);
    printf("%d\n", rooms);

    free(meetings); // Free allocated memory
    return 0;
}
