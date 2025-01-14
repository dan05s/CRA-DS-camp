#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top; //top을 수정하는것이 포인트
} Stack;

void initStack(Stack* stack) {//스택 초기화
    stack->top =  -1;
}

int getSize(Stack* stack){ //스택의 크기를 반환한다
    return stack->top + 1;
}

int isEmpty(Stack* stack){ //스택이 비어있는지 반환한다
    return stack->top == -1;
}

int isFull(Stack* stack){ //스택이 가득 찼는지 반환한다
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item){ //스택에 특정 값을 푸쉬한다.
    if (isFull(stack)){
        printf("Stack overflow!\n");
    }else{
        stack->data[++(stack->top)] = item;
    }
}

void pop(Stack* stack){ //맨 위에 있는 값을 팝 한다.
    if (isEmpty(stack)){
        printf("Stack underflow!\n");
    }else{
        --(stack->top);
    }
}

int peek(Stack* stack){ //스택에서 맨 위에 있는 값을 반환한다.
    if (isEmpty(stack)){
        printf("stack is empty!\n");
        return 0;
    }
    return stack->data[stack->top];
}

int main() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    initStack(stack);
    printf("initializing finished.\n");
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    pop(stack);

    while(!isEmpty(stack)){
        printf("popped %d\n", peek(stack));
        pop(stack);
    }
    free(stack);

    return 0;
}