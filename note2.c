#include<stdio.h>

#define MAX_SIZE 100 // 스택의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int top;            // 스택의 맨 위를 가리키는 변수
} Stack;

// 스택 초기화
void initStack(Stack* stack);
// top -1로 초기화, 현재 스택에 아무런 값이 안들어오고 top은 가장 마지막으로 들어온 인덱스를 나타낸다.

// 스택 연산 함수
void push(Stack* stack, int item);
//stack구조체를 받고 stack에 추가할 값을 파라미터로 받아서 top에 해당하는
//위치에 입력받은 값을 저장하고 top의 값을 하나 증가 시킨다
void pop(Stack* stack);
//top이 -1이 아닐경우에 혹은 isEmpty를 호출해서 stack이 비어있는 지 확인을 먼저하고,
//비어있다면 top의 값을 하나 감소한다.

int peek(Stack* stack);
//top이 -1이 아닐경우에 혹은 isEmpty를 호출해서 stack이 비어있는 지 확인을 먼저하고,
//stack의 data에 top인덱스의 값을 반환한다.
int getSize(Stack* stack);
//top + 1의 값을 반환한다. top은 마지막으로 들어온 인덱스이기 때문이다.
int isEmpty(Stack* stack);
//top이 -1일 경우 1을 반환, 나머지는 0을 반환
int isFull(Stack* stack);
//top이 MAX_SIZE - 1일 경운 1을 반환, 나머지는 0을 반환

int main(){
    return 0;
}