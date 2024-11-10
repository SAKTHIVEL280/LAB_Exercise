#include <stdio.h>
#include <string.h>
#define MAX_HISTORY 100
typedef struct {
    char urls[MAX_HISTORY][100];
    int top;
} BrowserHistory;
void push(BrowserHistory *history, char *url) {
    if (history->top < MAX_HISTORY - 1) {
        strcpy(history->urls[++history->top], url);
    } else {
        printf("History stack is full.\n");
    }
}
void pop(BrowserHistory *history) {
    if (history->top >= 0) {
        history->top--;
    } else {
        printf("History stack is empty.\n");
    }
}
void displayHistory(BrowserHistory *history) {
    for (int i = 0; i <= history->top; i++) {
        printf("URL: %s\n", history->urls[i]);
    }
}
int main() {
    BrowserHistory myHistory;
    myHistory.top = -1;
    push(&myHistory, "http://example.com");
    push(&myHistory, "http://example.org");
    printf("Browser History:\n");
    displayHistory(&myHistory);
    pop(&myHistory);
    printf("Browser History after popping:\n");
    displayHistory(&myHistory);
    return 0;
}
