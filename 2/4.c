#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Move {
    char description[100];
    struct Move *next;
} Move;
typedef struct {
    Move *top;
} MoveStack;
void pushMove(MoveStack *stack, char *description) {
    Move *newMove = (Move *)malloc(sizeof(Move));
    strcpy(newMove->description, description);
    newMove->next = stack->top;
    stack->top = newMove;
}
void popMove(MoveStack *stack) {
    if (stack->top != NULL) {
        Move *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    } else {
        printf("Move stack is empty.\n");
    }
}
void displayMoves(MoveStack *stack) {
    Move *current = stack->top;
    while (current != NULL) {
        printf("Move: %s\n", current->description);
        current = current->next;
    }
}
int main() {
    MoveStack myMoves;
    myMoves.top = NULL;
    pushMove(&myMoves, "Move to A3");
    pushMove(&myMoves, "Capture at B4");
    printf("Player Moves:\n");
    displayMoves(&myMoves);
    popMove(&myMoves);
    printf("Player Moves after undo:\n");
    displayMoves(&myMoves);
    return 0;
}
