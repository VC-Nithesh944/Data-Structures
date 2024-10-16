#include <stdio.h>
#include <stdlib.h>

void push(int data, int stack[], int stack2[], int n, int *top1, int *top2) {
    if (*top1 == n - 1) {
        Transfer(stack, stack2, *top1, top2);
        printf("Stack Overflow!!\n");
        return;
    }
    stack[++(*top1)] = data;
}

void Transfer(int stack1[], int stack2[], int top1, int *top2) {
    if (top1 == -1) {
        printf("Stack Underflow!!\n");
        exit(1);
    }
    while (top1 != -1) {
        stack2[++(*top2)] = stack1[top1--];
    }
}

int Deque(int stack2[], int *top2) {
    if (*top2 == -1) {
        printf("Queue Underflow!!\n");
        exit(1);
    }
    return stack2[(*top2)--];
}

int Display(int stack2[], int *top2, int n) {
    if (*top2 == -1) {
        printf("Queue Underflow!!\n");
        return -1;
    }
    printf("The elements of the queue are: ");
    for (int i = *top2; i >=0 ; i--) {
        printf("%d ", stack2[i]);
    }
    printf("\n");
    return 0;
}


int main() {
    int n, choice, data;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    int stack1[n], stack2[n];
    int top1 = -1, top2 = -1;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                push(data, stack1, stack2, n, &top1, &top2);
                break;

            case 2:
                if (top2 == -1 && top1 != -1) {
                    Transfer(stack1, stack2, top1, &top2);
                    top1 = -1;
                }
                data = Deque(stack2, &top2);
                printf("Dequeued element: %d\n", data);
                break;

            case 3:
                Display(stack2, &top2, n);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
