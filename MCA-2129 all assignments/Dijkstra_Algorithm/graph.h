#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph Graph;

Graph *createGraph(int num_vertices);
void addEdge(Graph *graph, int src, int dest, int weight);
void dijkstra(Graph *graph, int source);
void freeGraph(Graph *graph);

#endif
