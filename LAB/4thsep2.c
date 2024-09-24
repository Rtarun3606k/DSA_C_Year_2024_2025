#include <stdio.h>
#include <stdlib.h>

#define MAX_PLANTS 100000

int main()
{
    int n;
    scanf("%d", &n);

    int plants[MAX_PLANTS];
    int days[MAX_PLANTS] = {0};
    int stack[MAX_PLANTS];
    int top = -1;
    int maxDays = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &plants[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int day = 0;

        // Pop from stack until the current plant is not greater than the top of the stack
        while (top >= 0 && plants[stack[top]] >= plants[i])
        {
            if (days[stack[top]] > day)
            {
                day = days[stack[top]];
            }
            top--;
        }

        // If the stack is not empty, increment the day count
        if (top >= 0)
        {
            day++;
        }

        days[i] = day;
        if (day > maxDays)
        {
            maxDays = day;
        }

        stack[++top] = i;
    }

    printf("%d\n", maxDays);

    return 0;
}