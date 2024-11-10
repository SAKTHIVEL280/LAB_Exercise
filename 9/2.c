#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5
typedef struct {
    int x, y;
} Point;
typedef struct Node {
    Point point;
    int g, h, f;
    struct Node *parent;
} Node;
int isValid(int grid[ROW][COL], Point pt) {
    return (pt.x >= 0) && (pt.x < ROW) && (pt.y >= 0) && (pt.y < COL) && (grid[pt.x][pt.y] == 1);
}
int isDestination(Point src, Point dest) {
    return (src.x == dest.x && src.y == dest.y);
}
int calculateH(Point pt, Point dest) {
    return abs(pt.x - dest.x) + abs(pt.y - dest.y);
}
void aStarSearch(int grid[ROW][COL], Point src, Point dest) {
    if (!isValid(grid, src) || !isValid(grid, dest)) {
        printf("Source or destination is invalid.\n");
        return;
    }

    if (isDestination(src, dest)) {
        printf("We are already at the destination.\n");
        return;
    }
    int closedList[ROW][COL] = {0};

    Node *nodes[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            nodes[i][j] = NULL;
        }
    }
    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->point = src;
    startNode->g = startNode->h = startNode->f = 0;
    startNode->parent = NULL;
    nodes[src.x][src.y] = startNode;
    Node *openList[ROW * COL];
    int openListSize = 0;
    openList[openListSize++] = startNode;
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};
    while (openListSize > 0) {
        Node *currentNode = openList[0];
        int currentIdx = 0;

        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIdx = i;
            }
        }
        openList[currentIdx] = openList[--openListSize];

        int x = currentNode->point.x;
        int y = currentNode->point.y;
        closedList[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int newX = x + row[i];
            int newY = y + col[i];

            if (isValid(grid, (Point){newX, newY})) {
                if (isDestination((Point){newX, newY}, dest)) {
                    nodes[newX][newY] = (Node *)malloc(sizeof(Node));
                    nodes[newX][newY]->point = (Point){newX, newY};
                    nodes[newX][newY]->parent = currentNode;
                    printf("Path found.\n");

                    Node *temp = nodes[newX][newY];
                    while (temp) {
                        printf("(%d, %d) <- ", temp->point.x, temp->point.y);
                        temp = temp->parent;
                    }
                    printf("\n");
                    return;
                }

                int gNew = currentNode->g + 1;
                int hNew = calculateH((Point){newX, newY}, dest);
                int fNew = gNew + hNew;

                if (closedList[newX][newY] == 0 && (!nodes[newX][newY] || nodes[newX][newY]->f > fNew)) {
                    nodes[newX][newY] = (Node *)malloc(sizeof(Node));
                    nodes[newX][newY]->point = (Point){newX, newY};
                    nodes[newX][newY]->g = gNew;
                    nodes[newX][newY]->h = hNew;
                    nodes[newX][newY]->f = fNew;
                    nodes[newX][newY]->parent = currentNode;

                    openList[openListSize++] = nodes[newX][newY];
                }
            }
        }
    }

    printf("Failed to find the path.\n");
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 1}
    };
    Point src = {0, 0};
    Point dest = {4, 4};
    aStarSearch(grid, src, dest);
    return 0;
}
