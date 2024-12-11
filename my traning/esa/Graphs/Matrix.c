#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct Graph
{
    int vertex;
    int adjMatrix[MAX][MAX];
} Graph;

void createGraph(Graph *graph)
{
    int from, to;
    printf("Enter the number of vertex: ");
    scanf("%d", &graph->vertex);

    for (int i = 0; i < graph->vertex; i++)
    {
        graph->adjMatrix[i][0] = 0;
        graph->adjMatrix[0][i] = 0;
        for (int j = 0; j < graph->vertex; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    while (1)
    {
        printf("\nEnter the from and to vertices:");
        scanf("%d %d", &from, &to);
        if (from > 0 && from <= graph->vertex && to > 0 && to <= graph->vertex)
        {
            graph->adjMatrix[from][to] = 1;
            // g->adjMatrix[to][from]=1; //for undirected
        }
        else
            break;
    }
}

void printgraph(Graph *graph)
{
    for (int i = 0; i < graph->vertex; i++)
    {
        printf("\n");
        for (int j = 0; j < graph->vertex; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", graph->adjMatrix[i][j]);
            }
        }
    }
}

int main()
{
    int a, b, c;
    a = 5; // Number of vertices
    b = 6; // Number of edges
    c = 0; // Graph is undirected
    Graph graph;
    graph.vertex = a;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph.adjMatrix[i][j] = 0;
        }
    }

    // Hardcoded edges
    int edges[6][2] = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {5, 1}};

    for (int i = 0; i < b; i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        graph.adjMatrix[from][to] = 1;
        if (c == 0) // If the graph is undirected
        {
            graph.adjMatrix[to][from] = 1;
        }
    }

    printgraph(&graph);

    return 0;
}