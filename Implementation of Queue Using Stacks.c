#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int stack1[MAX_SIZE];  // Stack1 for pushing elements
    int stack2[MAX_SIZE];  // Stack2 for popping/peeking elements
    int top1;              // Top of stack1
    int top2;              // Top of stack2
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj-> top1 == MAX_SIZE -1) {
        printf(" Queue Overflow!\n");
        return;
    }
    obj-> stack1[++(obj-> top1)] =x;
}

void transferStacks(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj-> stack2[++(obj ->top2)] = obj-> stack1[obj ->top1--];
    }
}

int myQueuePop(MyQueue* obj) {
    if (obj-> top2 == -1) {
        transferStacks(obj);
    }
    if (obj-> top2 == -1) {
        printf(" Queue Underflow!\n");
        return -1;
    }
    return obj-> stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        transferStacks(obj);
    }
    if (obj-> top2 == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
