#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int num_vertices;
    int **adj_matrix;
    int *dist;
    int *visited;
} Graph;

Graph *createGraph(int num_vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    graph->dist = (int *)malloc(num_vertices * sizeof(int));
    graph->visited = (int *)malloc(num_vertices * sizeof(int));

    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        graph->dist[i] = INT_MAX;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    graph->adj_matrix[src][dest] = weight;
}

void dijkstra(Graph *graph, int source) {
    int num_vertices = graph->num_vertices;
    int *dist = graph->dist;
    int *visited = graph->visited;
    int **adj_matrix = graph->adj_matrix;

    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = -1;
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && adj_matrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + adj_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_matrix[u][v];
            }
        }
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph->dist);
    free(graph->visited);
    free(graph);
}

int main() {
    int num_vertices, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    Graph *graph = createGraph(num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            int weight;
            scanf("%d", &weight);
            if (weight != 0) {
                addEdge(graph, i, j, weight);
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, graph->dist[i]);
    }

    freeGraph(graph);
    return 0;
}
