#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;
typedef struct {
    Node **head;
    int n;
} Graph;
Node *createNode(int vertex, int weight) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    graph->head = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}
void addEdge(Graph *graph, int u, int v, int weight) {
    Node *newNode = createNode(v, weight);
    newNode->next = graph->head[u];
    graph->head[u] = newNode;

    newNode = createNode(u, weight);
    newNode->next = graph->head[v];
    graph->head[v] = newNode;
}
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist
