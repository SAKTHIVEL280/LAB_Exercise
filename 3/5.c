#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Customer {
    char name[100];
    struct Customer *next;
} Customer;
typedef struct {
    Customer *front;
    Customer *rear;
} CustomerQueue;
void enqueueCustomer(CustomerQueue *queue, char *name) {
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newCustomer;
        queue->rear = newCustomer;
    } else {
        queue->rear->next = newCustomer;
        queue->rear = newCustomer;
    }
}
void dequeueCustomer(CustomerQueue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        Customer *temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
    }
}
void displayQueue(CustomerQueue *queue) {
    Customer *current = queue->front;
    while (current != NULL) {
        printf("Customer: %s\n", current->name);
        current = current->next;
    }
}
int main() {
    CustomerQueue myQueue = {.front = NULL, .rear = NULL};
    enqueueCustomer(&myQueue, "Customer1");
    enqueueCustomer(&myQueue, "Customer2");
    printf("Customer Queue:\n");
    displayQueue(&myQueue);
    dequeueCustomer(&myQueue);
    printf("Customer Queue after dequeue:\n");
    displayQueue(&myQueue);
    return 0;
}
