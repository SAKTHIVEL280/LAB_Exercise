#include <stdio.h>
#include <ctype.h>

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

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top >= 0 && stack.data[stack.top] != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (stack.top >= 0 && precedence(stack.data[stack.top]) >= precedence(infix[i])) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (stack.top >= 0) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX_STACK];
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
