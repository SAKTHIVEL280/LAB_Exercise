#include <stdio.h>
#include <string.h>
#define MAX_QUEUE 100
typedef struct {
    char calls[MAX_QUEUE][100];
    int front, rear;
} CallQueue;
void enqueueCall(CallQueue *queue, char *call) {
    if ((queue->rear + 1) % MAX_QUEUE == queue->front) {
        printf("Queue is full.\n");
    } else {
        strcpy(queue->calls[queue->rear], call);
        queue->rear = (queue->rear + 1) % MAX_QUEUE;
    }
}
void dequeueCall(CallQueue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty.\n");
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE;
    }
}

void displayQueue(CallQueue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("Call: %s\n", queue->calls[i]);
        i = (i + 1) % MAX_QUEUE;
    }
}
int main() {
    CallQueue myQueue = {.front = 0, .rear = 0};
    enqueueCall(&myQueue, "Call1");
    enqueueCall(&myQueue, "Call2");
    printf("Call Queue:\n");
    displayQueue(&myQueue);
    dequeueCall(&myQueue);
    printf("Call Queue after dequeue:\n");
    displayQueue(&myQueue);
    return 0;
}
