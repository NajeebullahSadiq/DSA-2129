#include <stdio.h>
#include "graph.h"  // Include the graph.h header file

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
