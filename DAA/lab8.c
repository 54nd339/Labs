#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertices, edges;
    int *visited;
    int **adjMatrix;
} graph;

graph *createGraph(int vertices, int edges) {
    graph *g = malloc(sizeof(graph));
    g->vertices = vertices; g->edges = edges;
    g->adjMatrix = malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }

    int src, dest, weight;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i);
        scanf("%d %d %d", &src, &dest, &weight);
        g->adjMatrix[src][dest] = weight;
        g->adjMatrix[dest][src] = weight;
    }
    return g;
}
void printGraph(graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d is connected to: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->adjMatrix[i][j] != 0) {
                printf("%d (%d) ", j, g->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int minDistance(int *key, int *visited, int vertices) {
    int min = 9999, minIndex;
    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i]; minIndex = i;
        }
    }
    return minIndex;
}
void prim(graph *g, int start) {
    int *parent = malloc(g->vertices * sizeof(int));
    int *key = malloc(g->vertices * sizeof(int));
    g->visited = malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        key[i] = 9999;
        g->visited[i] = 0;
    }
    key[start] = 0;
    parent[start] = -1;
    for (int i = 0; i < g->vertices - 1; i++) {
        int u = minDistance(key, g->visited, g->vertices);
        g->visited[u] = 1;
        for (int v = 0; v < g->vertices; v++) {
            if (g->adjMatrix[u][v] && g->visited[v] == 0 && g->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adjMatrix[u][v];
            }
        }
    }

    int total = 0;
    for (int i = 1; i < g->vertices; i++) {
        printf("Edge %d: (%d) cost: %d\n", i, parent[i], g->adjMatrix[i][parent[i]]);
        total += g->adjMatrix[i][parent[i]];
    }
    printf("Total cost: %d\n", total);
}

void dijkstra(graph *g, int src) {
    int *dist = malloc(g->vertices * sizeof(int));
    int *visited = malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        dist[i] = 9999; visited[i] = 0;
    }
    dist[src] = 0;
    for (int i = 0; i < g->vertices - 1; i++) {
        int u = minDistance(dist, visited, g->vertices);
        visited[u] = 1;
        for (int v = 0; v < g->vertices; v++) {
            if (visited[v] == 0 && g->adjMatrix[u][v] != 0 && dist[u] != 9999 && dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < g->vertices; i++) {
        printf("%d ", dist[i]); sum += dist[i];
    }
    printf("\nTotal distance: %d\n", sum);
}

int main() {
    printf("Enter number of vertices: ");
    int vertices; scanf("%d", &vertices);
    printf("Enter number of edges: ");
    int edges; scanf("%d", &edges);
    graph *g = createGraph(vertices, edges);

    printf("\nGraph:\n");
    printGraph(g);

    printf("\nEnter start vertex: ");
    int start; scanf("%d", &start);

    printf("\nPrim's algorithm:\n");
    prim(g, start);

    printf("\nDijkstra's algorithm:\n");
    dijkstra(g, start);
    return 0;
}

/*
Enter number of vertices: 5
Enter number of edges: 7
Enter edge 0: 0 1 2
Enter edge 1: 0 3 6
Enter edge 2: 1 2 3
Enter edge 3: 1 3 8
Enter edge 4: 1 4 5
Enter edge 5: 2 4 7
Enter edge 6: 3 4 9

Graph:
Vertex 0 is connected to: 1 (2) 3 (6)
Vertex 1 is connected to: 0 (2) 2 (3) 3 (8) 4 (5)
Vertex 2 is connected to: 1 (3) 4 (7)
Vertex 3 is connected to: 0 (6) 1 (8) 4 (9)
Vertex 4 is connected to: 1 (5) 2 (7) 3 (9)

Enter start vertex: 0

Prim's algorithm:
Edge 1: (0) cost: 2
Edge 2: (1) cost: 3
Edge 3: (0) cost: 6
Edge 4: (1) cost: 5
Total cost: 16

Dijkstra's algorithm:

0 2 5 6 11
Total distance: 24
*/