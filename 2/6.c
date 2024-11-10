#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *stack, char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack *stack) {
    if (stack->top != NULL) {
        Node *temp = stack->top;
        char data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return data;
    } else {
        return '\0';
    }
}

int isSyntaxValid(char *code) {
    Stack stack;
    stack.top = NULL;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(' || code[i] == '{' || code[i] == '[') {
            push(&stack, code[i]);
        } else if (code[i] == ')' || code[i] == '}' || code[i] == ']') {
            char top = pop(&stack);
            if ((code[i] == ')' && top != '(') ||
                (code[i] == '}' && top != '{') ||
                (code[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }

    return stack.top == NULL;
}

int main() {
    char code[] = "{[()]}";
    if (isSyntaxValid(code)) {
        printf("The code is syntax valid.\n");
    } else {
        printf("The code has syntax errors.\n");
    }
    return 0;
}
