#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear =-1;

int empty(){
    return rear == -1;
}

int full(){
    return rear == MAX - 1;
}

void push(){
    if(full()){
        printf("queue is full! \n");
        return ;
    }
    rear ++
    queue[rear] = value;
}

void pop(){
    if(empty()){
        printf("queue is empty! \n");
        return ;
    }
    for(int i=0;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear --;
}

int main(){
    return 0;
}