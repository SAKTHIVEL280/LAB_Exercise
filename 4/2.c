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

int isBalanced(char *expr) {
    Stack stack;
    stack.top = NULL;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char top = pop(&stack);
            if ((expr[i] == ')' && top != '(') || (expr[i] == '}' && top != '{') || (expr[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }
    return stack.top == NULL;
}
int main() {
    char expr[] = "{[()]}";
    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }
    return 0;
}
