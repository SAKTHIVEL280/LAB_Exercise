#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RideRequest {
    char description[100];
    struct RideRequest *next;
} RideRequest;

typedef struct {
    RideRequest *front;
    RideRequest *rear;
} RideQueue;

void addRideRequest(RideQueue *queue, char *description) {
    RideRequest *newRequest = (RideRequest *)malloc(sizeof(RideRequest));
    strcpy(newRequest->description, description);
    newRequest->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newRequest;
        queue->rear = newRequest;
    } else {
        queue->rear->next = newRequest;
        queue->rear = newRequest;
    }
}

void serveRideRequest(RideQueue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        RideRequest *temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
    }
}

void displayQueue(RideQueue *queue) {
    RideRequest *current = queue->front;
    while (current != NULL) {
        printf("Ride Request: %s\n", current->description);
        current = current->next;
    }
}

int main() {
    RideQueue myQueue = {.front = NULL, .rear = NULL};

    addRideRequest(&myQueue, "Request1");
    addRideRequest(&myQueue, "Request2");

    printf("Ride Requests Queue:\n");
    displayQueue(&myQueue);

    serveRideRequest(&myQueue);

    printf("Ride Requests Queue after serving:\n");
    displayQueue(&myQueue);

    return 0;
}
