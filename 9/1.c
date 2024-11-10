#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
typedef struct {
    int vertices[MAX][MAX];
    int n;
} Graph;

void initializeGraph(Graph *graph, int n) {
    graph->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->vertices[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

void addEdge(Graph *graph, int u, int v, int w) {
    graph->vertices[u][v] = w;
    graph->vertices[v][u] = w;
}

void dijkstra(Graph *graph, int start) {
    int n = graph->n;
    int dist[n], visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX, u;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph->vertices[u][v] && dist[u] != INT_MAX && dist[u] + graph->vertices[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->vertices[u][v];
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    Graph graph;
    initializeGraph(&graph, 5);

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 4, 7);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);
    dijkstra(&graph, 0);
    return 0;
}
