#include<iostream> // input/output 라이브러리

using namespace std;

struct Node{
    int data;
    Node* next;
};

//head = nullptr

// head = (3, nullptr)

// 3 -> null
// 4 -> 3 -> null;
// 4 -> 3 -> 2 -> null
// 4 -> 3 -> 2 -> 1 -> null
// 3 -> 2 -> 1 -> null
// 3 -> 2 -> null

void display(Node* head){
    while(head != nullptr){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// 3 -> null
// 4 -> 3 -> null
// 4 -> 3 -> 2 -> null
// 4 -> 3 -> 2 -> 1 -> null
// 3 -> 2 -> 1 -> null
// 3 -> 2 -> null

int main(){
    Node* head = nullptr;
    head = new Node;
    head->data = 3;
    head->next = nullptr;
    display(head);
    // 3 -> null

    Node* a = new Node; // a head
    a->next = head;
    a->data = 4;
    head = a;
    display(head);
    // 4 -> 3 -> null
    //head->data 4 a->data 4

    Node* b = new Node;
    b->data = 2;
    b->next = nullptr;
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = b;
    display(head);
    // 4 -> 3 -> 2 -> null

    Node* c = new Node;
    c->data = 1;
    c->next = nullptr;
    Node* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = c;
    display(head);
    // 4 -> 3 -> 2 -> 1 -> null

    temp = head;
    head = head->next;
    delete temp;
    display(head);
    // 3 -> 2 -> 1 -> null

    tmp = head;
    while(tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    temp = tmp->next;
    tmp->next = nullptr;
    delete temp;
    display(head);
    // 3 -> 2 -> null

    return 0;
}
