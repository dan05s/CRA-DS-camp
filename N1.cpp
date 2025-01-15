#include <iostream>
using namespace std;

#define MAX_SIZE 100000


struct Stack{
    int data[MAX_SIZE];
    int top;
};

void initStack(Stack* stack) {
    stack->top =  -1;
}

int getSize(Stack* stack){
    return stack->top + 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

int isFull(Stack* stack){
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item){
    if (isFull(stack)){
        cout << "Stack overflow!\n" <<endl;
    }else{
        stack->data[++(stack->top)] = item;
    }
}

void pop(Stack* stack){
    if (isEmpty(stack)){
        cout << "Stack underflow!\n" << endl;
    }else{
        --(stack->top);
    }
}

int peek(Stack* stack){
    if (isEmpty(stack)){
        cout << "stack is empty!\n" << endl;
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack *stack = new Stack;
    initStack(stack);
    int k;
    int num;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> num;
        if(num == 0){
            pop(stack);
        }else{
            push(stack, num);
        }
    }
    int sum=0;
    for(int i=0;i<stack -> top+1;i++){
        sum = sum+ stack->data[i];
    }
    cout << sum << endl;
    delete stack;
    return 0;
}