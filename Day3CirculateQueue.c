#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 큐의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int front;          // 큐의 앞쪽을 가리키는 변수
    int rear;           // 큐의 뒤쪽을 가리키는 변수
    int size;           // 현재 큐에 있는 데이터 개수
} Queue;


void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

void freeQueue(Queue* queue) {
    free(queue);
}


// 큐가 비어있는지 확인
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// 큐가 가득 찼는지 확인
int isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

//큐가 시작부분
//front = -1, rear = -1 
// front , rear 둘다 실제 처음과 끝 위치 1 2 3 | 0 2
// front는 실제 값 위치, rear는 다음에 들어올 값 위치

/*
1. front, rear가 실제 위치 일때

front = -1, rear = -1, size = 0
1) enqueue, front = 0, rear = 0 , size = 1
2) enqueue, front = 0, rear = 1 , size = 2
3) dequeue, front = 1, rear = 1 , size = 1
4) dequeue, front = -1, rear = -1, size = 0

empty ? 
size == 0
full ?
size == MAX_SIZE


enqueue ?
if(full){
함수를 종료
}
if(empty){
    front = 0, rear = 0
}
else{
    rear = (rear+1) % MAX_SIZE
}
값 넣기기
size++

dequeue ?
if(empty){
함수를 종료
}
if(size == 1){
    front = -1, rear = -1
}
else{
    front = (front + 1) % MAX_SIZE
}
size--;
*/

//큐가 가득차는 부분
//큐가 다시 감소해서 텅 비게되는 부분

// 큐에 요소 추가 (enqueue)
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue %d.\n", item);
        return;
    }
    if(isEmpty(queue)){
        queue->front = 0;
        queue->rear = 0;
    }
    else{
        queue->rear = (queue->rear + 1) % MAX_SIZE; //rear++
    }
    queue->data[queue->rear] = item; //queue[rear] = value;
    queue->size++;
}

// 큐에서 요소 제거 (dequeue)
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return ; // 실패를 나타내는 값
    }
    if(queue->size == 1){
        queue->front = -1;
        queue->rear = -1;
    }
    else{
        queue->front = (queue->front + 1) % MAX_SIZE; // 1 % 100 == 1
    }
    queue->size--;// front rear 1, 
}

// 큐의 맨 앞 요소를 확인 (peek)
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // 실패를 나타내는 값
    }
    return queue->data[queue->front];
}

void display(Queue* queue){
    printf("front: %d/rear: %d/size: %d\n", queue->front, queue->rear, queue->size);
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    initQueue(queue);

    // 데이터 삽입
    printf("Enqueuing 10, 20, 30 into the queue...\n");
    display(queue);
    enqueue(queue, 10);
    display(queue);
    enqueue(queue, 20);
    display(queue);
    enqueue(queue, 30);
    display(queue);

    // 큐 크기 확인
    printf("Queue size: %d\n", queue->size);

    // 큐 맨 앞 요소 확인
    printf("Front element is: %d\n", peek(queue));

    // 데이터 제거
    printf("Dequeuing elements from the queue...\n");
    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", peek(queue));
        dequeue(queue);
        display(queue);
    }

    freeQueue(queue);

    return 0;
}
