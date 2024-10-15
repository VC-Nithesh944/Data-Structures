#include <stdio.h>

int isEmpty(int top) {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull(int top, int n) {
    if (top == n - 1)
        return 1;
    else
        return 0;
}

void push(int data, int *arr, int n, int *top) {
    if (isFull(*top, n)) {
        printf("Stack Overflow. %d can't be pushed into Stack\n", data);
        return;
    }
    *top += 1;
    arr[*top] = data;
}

int pop(int *arr, int *top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow \n");
        return -1; // return a default value or throw an error
    } else {
        int value = arr[*top--];
        return value;
    }
}

void Display(int *arr, int *top) {
    if (isEmpty(*top)) {
        printf("The Stack is Empty. No elements to display\n");
        return;
    }
    printf("\nThe elements of the stack are : ");
    for (int i = 0; i <= *top; i++) {
        printf("%d ", arr[i]);
    }
    printf("<- top \n");
}

int main() {
    int n;
    printf("Enter the size of the stack: ");
    if (scanf("%d", &n) != 1) {
        printf("Error reading input\n");
        return 1;
    }
    int stack[n];
    int top = -1;                   //Its best not to initialise this as *top 
    push(1, stack, n, &top);
    push(2, stack, n, &top);
    push(3, stack, n, &top);
    push(4, stack, n, &top);
    push(5, stack, n, &top);
    push(6, stack, n, &top);
    Display(stack, &top);
    printf("Popping: %d\n", pop(stack, &top));
    Display(stack, &top);
    return 0;
}
