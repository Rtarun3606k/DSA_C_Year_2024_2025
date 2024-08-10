// Given an integer array nums, return the most frequent even element. If there is a tie, return the smallest one. If there is no such element, return -1.

// Input Format

// line 1: number of elements
// line 2: n integers (space separated)
// Constraints

// 1<= nums.length <= 1000
// 0<=nums[i]<=999
// Output Format

// An even integer appearing most frequently, else -1

#include <stdio.h>

int mostFrequentEven(int nums[], int n)
{
    int count[1000] = {0}; // Initialize count array with 0
    int maxFreq = 0;
    int mostFrequentEven = -1;

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }

    // Find the most frequent even element
    for (int i = 0; i < 1000; i += 2)
    {
        if (count[i] > maxFreq)
        {
            maxFreq = count[i];
            mostFrequentEven = i;
        }
    }

    return mostFrequentEven;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = mostFrequentEven(nums, n);
    printf("ans %d\n", result);

    return 0;
}
