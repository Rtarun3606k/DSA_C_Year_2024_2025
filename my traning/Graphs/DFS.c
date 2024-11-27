#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct
{
    int items[MAX];
    int top;
} Stack;

// Graph structure
typedef struct
{
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

// Function to create a stack
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to perform DFS using stack
void DFSUtil(Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i])
        {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFSIMPLEMENTTATION(Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i])
        {
            DFSIMPLEMENTTATION(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int startVertex)
{
    int visited[MAX] = {0};
    // DFSUtil(graph, startVertex, visited);
    DFSIMPLEMENTTATION(graph, startVertex, visited);
}

int main()
{
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    DFS(graph, 0);

    return 0;
}