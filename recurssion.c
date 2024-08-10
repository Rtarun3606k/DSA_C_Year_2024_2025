#include <stdio.h>
#include <ctype.h>
#include <string.h>

int fact(int a);
// calculate sum of digit using recursion

int sum(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else
    {
        return a % 10 + sum(a / 10);
    }
}

// calculate count of digit using recursion

int count(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else
    {
        return 1 + count(a / 10);
    }
}

int main()
{
    int a = 2, *b, c;
    b = &a;
    printf("the value of a :");
    scanf("%d", &a);
    int res = fact(a);
    printf("the factorial of %d is %d\n", a, res);
    // printf("the factorial of %d is %d", a, res);
    printf("the sum of digit of %d is %d\n", a, sum(a));
    printf("the count of digit of %d is %d\n", a, count(a));
    int result_count = count(a);
    if (result_count > 9)
    {
        while (result_count >= 9)
        {
            result_count = count(result_count);
            printf("the count of digit of %d \n", result_count);
        }
    }

    printf("the count of digit of %d \n", result_count);

    return 0;
}

int fact(int a)
{
    if (a == 1)
    {
        return 1;
    }
    else
    {
        return a * fact(a - 1);
    }
}