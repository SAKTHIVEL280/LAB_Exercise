#include <stdio.h>
#include <string.h>

#define MAX_CHANGES 100

typedef struct {
    char changes[MAX_CHANGES][100];
    int top;
} ChangeStack;

void pushChange(ChangeStack *stack, char *change) {
    if (stack->top < MAX_CHANGES - 1) {
        strcpy(stack->changes[++stack->top], change);
    } else {
        printf("Change stack is full.\n");
    }
}

void popChange(ChangeStack *stack) {
    if (stack->top >= 0) {
        stack->top--;
    } else {
        printf("Change stack is empty.\n");
    }
}

void displayChanges(ChangeStack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("Change: %s\n", stack->changes[i]);
    }
}

int main() {
    ChangeStack myChanges;
    myChanges.top = -1;

    pushChange(&myChanges, "Add header");
    pushChange(&myChanges, "Fix typo");

    printf("Changes:\n");
    displayChanges(&myChanges);

    popChange(&myChanges);

    printf("Changes after undo:\n");
    displayChanges(&myChanges);

    return 0;
}
