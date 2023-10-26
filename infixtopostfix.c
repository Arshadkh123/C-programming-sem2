#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

struct Stack {
    int top;
    char items[MAX_STACK_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack is full.\n");
        exit(1);
    }
    stack->items[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    struct Stack stack;
    initialize(&stack);

    int i, j;
    for (i = 0, j = -1; infix[i]; i++) {
        if (infix[i] >= 'A' && infix[i] <= 'Z') {
            postfix[++j] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[++j] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack);
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.items[stack.top])) {
                postfix[++j] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[++j] = pop(&stack);
    }

    postfix[++j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
