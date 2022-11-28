#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertices;
    int **adjMatrix;
} graph;

graph *createGraph(int vertices) {
    graph *g = malloc(sizeof(graph));
    g->vertices = vertices;
    g->adjMatrix = malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        g->adjMatrix[i] = malloc(vertices * sizeof(int));
    return g;
}
void addEdge(graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}
void printGraph(graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d is connected to: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->adjMatrix[i][j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}

void BFS(graph *g, int start) {
    int *visited = malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++)
        visited[i] = 0;
    int *queue = malloc(g->vertices * sizeof(int));
    int front = -1, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(graph *g, int start) {
    int *visited = malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++)
        visited[i] = 0;
    int *stack = malloc(g->vertices * sizeof(int));
    int top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1) {
        int current = stack[top--];
        printf("%d ", current);
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    int vertices; scanf("%d", &vertices);
    graph *g = createGraph(vertices);

    printf("Enter the number of edges: ");
    int edges; scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter the edges (src dest): ");
        int src, dest; scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    printf("\nThe graph is:\n");
    printGraph(g);

    printf("\nBFS: "); BFS(g, 0);
    printf("\nDFS: "); DFS(g, 0);
    printf("\n"); return 0;
}

/*
Enter the number of vertices: 5
Enter the number of edges: 5
Enter the edges (src dest): 0 1
Enter the edges (src dest): 0 4
Enter the edges (src dest): 1 2
Enter the edges (src dest): 1 3
Enter the edges (src dest): 1 4

The graph is:
Vertex 0 is connected to: 1 4
Vertex 1 is connected to: 0 2 3 4
Vertex 2 is connected to: 1
Vertex 3 is connected to: 1
Vertex 4 is connected to: 0 1

BFS: 0 1 4 2 3
DFS: 0 4 1 3 2
*/