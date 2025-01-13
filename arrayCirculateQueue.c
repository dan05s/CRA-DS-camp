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
    if(isFull(queue)){
        printf("Queue overflow!\n");
    }else{
    queue -> rear = (queue -> rear + 1) % MAX_SIZE;
    queue -> data[queue -> rear] = item;
    queue -> size ++;
    }
}

int dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue underflow!\n");
        return -1;
    }else{
    int item = queue -> data[queue -> front];
    queue -> front = (queue -> front +1) & MAX_SIZE;
    queue -> size --;
    return item;
    }   
}

int peak(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue underflow!\n");
        return -1;
    }
    return queue -> data[queue -> front];
}



int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    printf("initializing finished!\n");

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    dequeue(queue);
    enqueue(queue,40);
    dequeue(queue);
    enqueue(queue,50);
    enqueue(queue,60);
    printf("Queue size: %d\n",getSize(queue));
    
    while(!isEmpty(queue)){
        printf("Dequeued %d\n",dequeue(queue));
    }

    freeQueue(queue);

    return 0;
}
