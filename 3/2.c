#include <stdio.h>
#include <string.h>
#define MAX_QUEUE 100
typedef struct {
    char customers[MAX_QUEUE][100];
    int front, rear;
} BookingQueue;
void addCustomer(BookingQueue *queue, char *customer) {
    if ((queue->rear + 1) % MAX_QUEUE == queue->front) {
        printf("Queue is full.\n");
    } else {
        strcpy(queue->customers[queue->rear], customer);
        queue->rear = (queue->rear + 1) % MAX_QUEUE;
    }
}
void serveCustomer(BookingQueue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty.\n");
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE;
    }
}
void displayQueue(BookingQueue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("Customer: %s\n", queue->customers[i]);
        i = (i + 1) % MAX_QUEUE;
    }
}
int main() {
    BookingQueue myQueue = {.front = 0, .rear = 0};
    addCustomer(&myQueue, "Customer1");
    addCustomer(&myQueue, "Customer2");
    printf("Booking Queue:\n");
    displayQueue(&myQueue);
    serveCustomer(&myQueue);
    printf("Booking Queue after serving:\n");
    displayQueue(&myQueue);
    return 0;
}
