#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int u, v, w;
} Edge;
typedef struct {
    Edge edges[MAX];
    int n, e;
} Graph;
typedef struct {
    int parent[MAX];
    int rank[MAX];
} DisjointSet;
void makeSet(DisjointSet *ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}
int find(DisjointSet *ds, int u) {
    if (u != ds->parent[u]) {
        ds->parent[u] = find(ds, ds->parent[u]);
    }
    return ds->parent[u];
}
void unionSets(DisjointSet *ds, int u, int v) {
    int uRoot = find(ds, u);
    int vRoot = find(ds, v);

    if (uRoot != vRoot) {
        if (ds->rank[uRoot] > ds->rank[vRoot]) {
            ds->parent[vRoot] = uRoot;
        } else {
            ds->parent[uRoot] = vRoot;
            if (ds->rank[uRoot] == ds->rank[vRoot]) {
                ds->rank[vRoot]++;
            }
        }
    }
}
int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}
void kruskalMST(Graph *g) {
    DisjointSet ds;
    makeSet(&ds, g->n);

    qsort(g->edges, g->e, sizeof(Edge), compare);

    printf("Edges in MST:\n");
    for (int i = 0, count = 0; count < g->n - 1 && i < g->e; i++) {
        Edge e = g->edges[i];
        int u = find(&ds, e.u);
        int v = find(&ds, e.v);
        if (u != v) {
            printf("Edge (%d, %d) with weight %d\n", e.u, e.v, e.w);
            unionSets(&ds, u, v);
            count++;
        }
    }
}
int main() {
    Graph g;
    g.n = 4; // Number of vertices
    g.e = 5; // Number of edges

    g.edges[0] = (Edge){0, 1, 10};
    g.edges[1] = (Edge){0, 2, 6};
    g.edges[2] = (Edge){0, 3, 5};
    g.edges[3] = (Edge){1, 3, 15};
    g.edges[4] = (Edge){2, 3, 4};
    kruskalMST(&g);
    return 0;
}
