#include <stdio.h>
#include <string.h>
#define MAX_QUEUE 100

typedef struct {
    char jobs[MAX_QUEUE][100];
    int front, rear;
} PrintQueue;
void enqueue(PrintQueue *queue, char *job) {
    if ((queue->rear + 1) % MAX_QUEUE == queue->front) {
        printf("Queue is full.\n");
    } else {
        strcpy(queue->jobs[queue->rear], job);
        queue->rear = (queue->rear + 1) % MAX_QUEUE;
    }
}
void dequeue(PrintQueue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty.\n");
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE;
    }
}

void displayQueue(PrintQueue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("Job: %s\n", queue->jobs[i]);
        i = (i + 1) % MAX_QUEUE;
    }
}
int main() {
    PrintQueue myQueue = {.front = 0, .rear = 0};
    enqueue(&myQueue, "Job1");
    enqueue(&myQueue, "Job2");
    printf("Print Queue:\n");
    displayQueue(&myQueue);
    dequeue(&myQueue);
    printf("Print Queue after dequeue:\n");
    displayQueue(&myQueue);
    return 0;
}
