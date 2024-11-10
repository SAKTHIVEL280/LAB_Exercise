#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Inquiry {
    char description[100];
    struct Inquiry *next;
} Inquiry;
typedef struct {
    Inquiry *front;
    Inquiry *rear;
} InquiryQueue;
void addInquiry(InquiryQueue *queue, char *description) {
    Inquiry *newInquiry = (Inquiry *)malloc(sizeof(Inquiry));
    strcpy(newInquiry->description, description);
    newInquiry->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newInquiry;
        queue->rear = newInquiry;
    } else {
        queue->rear->next = newInquiry;
        queue->rear = newInquiry;
    }
}
void resolveInquiry(InquiryQueue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        Inquiry *temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
    }
}
void displayInquiries(InquiryQueue *queue) {
    Inquiry *current = queue->front;
    while (current != NULL) {
        printf("Inquiry: %s\n", current->description);
        current = current->next;
    }
}
int main() {
    InquiryQueue myQueue = {.front = NULL, .rear = NULL};
    addInquiry(&myQueue, "Inquiry1");
    addInquiry(&myQueue, "Inquiry2");
    printf("Inquiry Queue:\n");
    displayInquiries(&myQueue);
    resolveInquiry(&myQueue);
    printf("Inquiry Queue after resolving:\n");
    displayInquiries(&myQueue);
    return 0;
}
