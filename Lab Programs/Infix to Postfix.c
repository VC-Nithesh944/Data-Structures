#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if the stack is empty
int isEmpty(int top) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the precedence of a symbol
int precedence(char symbol) {
    switch (symbol) {
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to push a symbol onto the stack
void push(char data, char stack[], int *top, int n) {
    if (*top == n - 1) {
        printf("Stack Overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = data;
}

// Function to pop a symbol from the stack
char pop(char stack[], int *top, int n) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char value = stack[*top];
    *top = *top - 1;
    return value;
}

// Function to convert infix to postfix
void intoPost(char infix[], char postfix[], char stack[], int *top, int n) {
    int i = 0, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol, stack, top, n);
                break;
            case ')':
                while ((next = pop(stack, top, n)) != '(') {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isEmpty(*top) && precedence(stack[*top]) >= precedence(symbol)) {
                    postfix[j++] = pop(stack, top, n);
                }
                push(symbol, stack, top, n);
                break;
            default:
                postfix[j++] = symbol;
                break;
        }
    }
    while (!isEmpty(*top)) {
        postfix[j++] = pop(stack, top, n);
    }
    postfix[j] = '\0';
}

int main() {
    int n = 100;
    char stack[n], postfix[n], infix[n];
    int top = -1;

    printf("Enter the infix Expression: ");
    gets(infix);

    intoPost(infix, postfix, stack, &top, n);

    printf("The postfix Expression: %s\n", postfix);

    return 0;
}
