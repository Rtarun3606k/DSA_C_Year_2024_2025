#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graphs
{
    int numberOfVertices;
    Node **adjList;
    int isDirected;
} Graphs;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = data;
    newNode->next = NULL;
    return newNode;
}

Graphs *createGraphs(int vertices, int isDirected)
{
    Graphs *graph = (Graphs *)malloc(sizeof(Graphs));
    graph->numberOfVertices = vertices;
    graph->isDirected = isDirected;

    graph->adjList = malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graphs *graph, int sorce, int destination)
{
    Node *newNode = createNode(destination);
    newNode->next = graph->adjList[sorce];
    graph->adjList[sorce] = newNode;

    if (!graph->isDirected)
    {
        newNode = createNode(sorce);
        newNode->next = graph->adjList[sorce];
        graph->adjList[sorce] = newNode;
    }
}

void printgraphs(Graphs *graph)
{
    printf("Vertex: Adjacency List\n");
    for (int i = 0; i < graph->numberOfVertices; i++)
    {
        Node *temp = graph->adjList[i];
        printf("%d --->", i);
        while (temp)
        {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main()
{
    int a, b, c;
    a = 5; // Number of vertices
    b = 6; // Number of edges
    c = 0; // Graph is undirected

    Graphs *graph = createGraphs(a, c);

    int edges[6][2] = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {3, 4}};

    for (int i = 0; i < b; i++)
    {
        addEdge(graph, edges[i][0], edges[i][1]);
    }

    printgraphs(graph);

    return 0;
}