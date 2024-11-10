#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Task {
    char description[100];
    struct Task *next;
} Task;
typedef struct {
    Task *head;
} TaskList;
void addTask(TaskList *list, char *description) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    strcpy(newTask->description, description);
    newTask->next = list->head;
    list->head = newTask;
}
void removeTask(TaskList *list) {
    if (list->head == NULL) {
        printf("Task list is empty.\n");
        return;
    }
    Task *current = list->head;
    Task *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous != NULL) {
        previous->next = NULL;
    } else {
        list->head = NULL;
    }
    free(current);
}
void displayTasks(TaskList *list) {
    Task *current = list->head;
    while (current != NULL) {
        printf("Task: %s\n", current->description);
        current = current->next;
    }
}
int main() {
    TaskList myTasks;
    myTasks.head = NULL;
    addTask(&myTasks, "Finish report");
    addTask(&myTasks, "Buy groceries");
    printf("Tasks:\n");
    displayTasks(&myTasks);
    removeTask(&myTasks);
    printf("Tasks after removal:\n");
    displayTasks(&myTasks);
    return 0;
}
