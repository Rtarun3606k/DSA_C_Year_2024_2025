#include <stdio.h>
#include <ctype.h>
#include <string.h>

int insert_at_end(int arr[], int size, int element, int capacity, int index);
int display(int arr[], int size);
int bubble_sort(int arr[], int size);
int input_arr(int arr[], int size);

int main()
{
    int arr[100], size, index, element;
    printf("Enter the element to insert in the array\n");
    scanf("%d", &element);
    printf("Enter the index to insert  the element in  array\n");
    scanf("%d", &index);
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    input_arr(arr, size);
    display(arr, size);
    insert_at_end(arr, size, element, 100, index);
    printf("elements after  insertrion\n");
    // char str[100];
    // how to make an array of strings
    // char str2[100][100];
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("Enter a string %d: ", i + 1);
    //     scanf("%s", str2[i]);
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("string %d: %s\n", i, str2[i]);
    // }
    display(arr, size + 1);
    bubble_sort(arr, size + 1);
    printf("elements after  sorting\n");
    display(arr, size + 1);

    return 0;
}

int insert_at_end(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    else
    {
        // printf("size: %d\n", size);
        for (int i = capacity - 1; i >= size; i--)
        {
            // printf("i: %d\n", i);

            arr[i + 1] = arr[i];
        }
        // printf("size: %d\n", size);

        arr[index] = element;
        return 1;
    }
}

int display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}

int bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int input_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return 0;
}

// bubblesort algo?
//  Bubble Sort Algorithm
//  for (int i = 0; i < size - 1; i++)
//  {
//      for (int j = 0; j < size - 1 - i; j++)
//      {
//          if (arr[j] > arr[j + 1])
//          {
//              int temp = arr[j];
//              arr[j] = arr[j + 1];
//              arr[j + 1] = temp;
//          }
//      }
//  }
