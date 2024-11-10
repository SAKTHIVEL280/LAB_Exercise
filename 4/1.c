#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK 100
typedef struct {
    int data[MAX_STACK];
    int top;
} Stack;
void push(Stack *stack, int value) {
    if (stack->top < MAX_STACK - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack is full.\n");
    }
}
int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}
int evaluatePostfix(char *expression) {
    Stack stack;
    stack.top = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            continue;
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (expression[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }
    return pop(&stack);
}
int main() {
    char expression[] = "2 3 4 + *";
    printf("Postfix evaluation: %d\n", evaluatePostfix(expression));
    return 0;
}
