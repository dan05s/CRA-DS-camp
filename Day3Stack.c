#include<stdio.h>

#define MAX 50

char stack[MAX]; //데이터를 저장할 공간
int top = -1;   //가장 마지막에 들어온 원소의 인덱스

//부가 기능
int empty(){
    return top == -1;
}
int full(){
    return top == MAX - 1;
}

//스택의 메인기능
void push(char value){
    //스택이 가득 차있는지 확인
    if(full()){
        printf("stack is full! \n");
        return ;
    }
    top++;
    stack[top] = value;
}
void pop(){
    //스택이 비어있는지 확인
    if(empty()){
        printf("stack is empty! \n");
        return ;
    }
    top--;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int isWrong = 0;
        char arr[50];
        scanf("%s", arr);
        for(int j = 0; j < 50; j++){
            if(arr[j] == '('){
                push(arr[j]);
            }
            if(arr[j] == ')'){
                if(empty()){
                    isWrong = 1;
                    break;
                }
                else{
                    pop();
                }
            }
        }
        if(isWrong || empty() == 0){
            printf("NO\n");
            top = -1;
        }
        else{
            printf("YES\n");
        }
    }
}