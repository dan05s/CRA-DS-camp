#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 25

struct Stack {
    string data[MAX_SIZE];
    int top;
    int count;
};

void initStack(Stack* stack) {
    stack->top = -1;
    stack -> count =0;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, string item) {
    if (isFull(stack)) {
        cout << "Stack overflow!\n";
    } else {
        stack->data[++(stack->top)] = item;
    }
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow!\n";
    } else {
        --(stack->top);
    }
}

string peek(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty!\n";
        return "";
    }
    return stack->data[stack->top];
}

void check(Stack* stack, string sentence) {
    string word = "";
    for (int i = 0; i <= sentence.length(); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            if (!word.empty()) {
                push(stack, word);
                word = "";
            }
        } else {
            word += sentence[i];
        }
    }
}

void display(Stack* stack) {
    while (!isEmpty(stack)) {
        cout << peek(stack) << " ";
        pop(stack);
    }
}

int main() {
    Stack* stack = new Stack;
    initStack(stack);

    int k;
    cin >> k;

    string sentence;
    for(int i = 0; i < k; i++) {
        getline(cin, sentence);
    
    }

    for(int i = 0; i < k; i++){

    }

    delete stack;
    return 0;
}