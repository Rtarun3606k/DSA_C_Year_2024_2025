#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
// 3-1 = 2 -i = 0
// 3-1-1=1
// 3-1-2=0
{
    int a, b, c;
    char *str1 = "wow", *str2 = "ww";
    int n = strlen(str1);
    int followup = 0;
    for (int i = 0; i < n; i++)
    {
        int b = n - 1 - i; // reversing the string
        char var1 = str1[i], var2 = str2[b];
        if (var1 != var2)
        {
            followup = 1;
            // printf("not palindrome");
            break;
        }
        else
        {
            followup = 0;
            // printf("not palindrome");
            // break;
        }
    }

    if (followup == 0)
    {
        printf("palindrome");
    }
    else
    {
        printf("!palindrome");
    }

    return 0;
}
