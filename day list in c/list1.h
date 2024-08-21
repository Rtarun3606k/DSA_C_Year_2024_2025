#define MAX 3
// #include <stdio.h>
typedef struct arraylist
{
    int last;
    int a[MAX];
} ARLST;

void initlist(ARLST *l);
int append(ARLST *l, int ele);
int deleteLast(ARLST *l, int *ele);
void display(ARLST *l);
void statusTeller(int status);
// ARLST al;
// void statusTeller(int status)
// {
//     if (status == 1)
//         printf("Success\n");
//     else
//     {
//         printf("Failure\n");
//         // break;
//     }
// }