#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int start)
{
    // int visited;
    printf("Visited %d\n", start);
    visited[start] = 1;
    for (int i = 0; i < 7; i++)
    {
        if (A[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int a, b, c;
    printf("Enter the starting vertex: ");
    scanf("%d", &a);
    DFS(a);

    return 0;
}