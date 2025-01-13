#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void initQueue(Queue* queue){
    queue -> front = 0;
    queue -> rear = -1;
    queue -> size = 0;
}

void freeQueue(Queue *queue){
    free(queue);
}

int getSize(Queue* queue){
    return queue -> size;
}

int isEmpty(Queue* queue){
   return (queue -> size == 0);
}

int isFull(Queue* queue){
    return (queue -> size == MAX_SIZE);
}

void enqueue(Queue* queue, int item){
    queue -> rear = (queue -> rear + 1) % MAX_SIZE;
    queue -> data[queue -> rear] = item;
    queue -> size ++;
}

int dequeue(Queue* queue){

    int item = queue -> data[queue -> front];
    queue -> front = (queue -> front +1) & MAX_SIZE;
    queue -> size --;
    return item;
}

int peak(Queue* queue){
    return queue -> data[queue -> front];
}



int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    printf("initializing finished!\n");



    return 0;
}
