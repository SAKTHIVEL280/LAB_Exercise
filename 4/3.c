#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK 100
typedef struct {
    char data[MAX_STACK];
    int top;
} Stack;
void push(Stack *stack, char value) {
    if (stack->top < MAX_STACK - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack is full.\n");
    }
}
char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack is empty.\n");
        return '\0';
    }
}
void reverseString(char *str) {
    Stack stack;
    stack.top = -1;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }
    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}
int main() {
    char str[] = "Hello World!";
    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);
    return 0;
}
