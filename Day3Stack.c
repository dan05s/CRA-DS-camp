#include <stdio.h>

#define MAX 50

char stack[MAX];
int top = -1;

int empty() {
    return top == -1;
}

int full() {
    return top == MAX - 1;
}

void push(char value) {
    if (full()) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = value;
}

void pop() {
    if (empty()) {
        printf("Stack is empty!\n");
        return;
    }
    top--;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int isWrong =0;
        char arr[50];
        scanf("%s", arr);
       for(int j=0;j<50;j++){
        if(arr[j]=='('){
            push(arr[j]);
        }
        if(arr[j]==')'){
            if(empty()){
                isWrong =1;
                break;
            }else{
                pop();
            }
        }
       }
        if(isWrong || empty()==0){
            printf("NO\n");
            top = -1;
        }else{
            printf("YES\n");
        }
    }

    return 0;
}