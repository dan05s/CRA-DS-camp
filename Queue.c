#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->front == (queue->rear + 1) % MAX_SIZE;
}

int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    printf("Input: %d\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Null\n");
        return -1;
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return item;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Null\n");
        return -1;
    }
    return queue->data[queue->front];
}

int getSize(Queue* queue) {
    return (queue->rear - queue->front + 1 + MAX_SIZE) % MAX_SIZE;
}

int main() {
    return 0;
}