#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // 두 개의 인자를 받는 생성자를 추가
    Node(int value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
};

// head 노드 앞에 새로운 노드를 추가하는 함수
Node* push_front(Node* head, int value) {
    Node* newNode = new Node(value, head);  // 원래 있던 head가 다음 노드인 새 노드를 만든다
    return newNode;
}

// 리스트의 끝에 새로운 노드를 추가하는 함수
Node* push_back(Node* head, int value) {
    Node* newNode = new Node(value, nullptr);  // 다음 노드가 nullptr인 새로운 마지막 노드 추가
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {  // 리스트의 끝을 찾기 위한 반복문
        temp = temp->next;
    }
    temp->next = newNode;  // 마지막 노드의 next를 새 노드로 설정
    return head;
}

// head 노드를 제거하는 함수
Node* pop_front(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;  // 리스트가 비었을 때의 처리
        return nullptr;
    }
    Node* temp = head;
    head = head->next;  // head를 두 번째 노드를 가리키도록 업데이트
    delete temp;  // 원래의 head 노드 삭제
    return head;
}

// 리스트의 끝에서 노드를 제거하는 함수
Node* pop_back(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;  // 리스트가 비었을 때의 처리
        return nullptr;
    }
    if (head->next == nullptr) {  // 리스트에 노드가 하나만 있을 때
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {  // 마지막에서 두 번째 노드까지 이동
        temp = temp->next;
    }
    delete temp->next;  // 마지막 노드 삭제
    temp->next = nullptr;  // 마지막 두 번째 노드의 next를 nullptr로 설정
    return head;
}

// key 값 뒤에 새로운 노드를 삽입하는 함수
Node* insert(Node* head, int key, int value) {
    if (head == nullptr) {
        cout << "List is empty! Cannot insert after key " << key << "." << endl;
        return head;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {  // key를 찾기 위한 반복문
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "key " << key << " not found in the list!" << endl;
        return head;
    }
    Node* newNode = new Node(value, temp->next);  // 새로 temp 다음에 연결되어야 할 노드 생성
    temp->next = newNode;  // key 값 뒤에 새 노드 연결
    return head;
}

// 리스트에서 특정 값을 제거하는 함수
Node* remove(Node* head, int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;  // 리스트가 비었을 때 처리
    }
    if (head->data == value) {
        return pop_front(head);  // value가 head 노드일 경우 pop_front 호출
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {  // value를 찾기 위한 반복문
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Value " << value << " not found" << endl;  // value가 리스트에 없을 때 처리
        return head;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;  // value를 가진 노드 삭제
    return head;
}

// 리스트를 모두 비우는 함수
Node* clear(Node* head) {
    while (head != nullptr) {
        head = pop_front(head);  // pop_front로 리스트에서 노드 하나씩 삭제
    }
    return nullptr;
}

// 리스트의 모든 노드를 출력하는 함수
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " - ";  // 각 노드의 데이터 출력
        temp = temp->next;
    }
    cout << endl;  // 마지막에 줄바꿈
}

int main() {
    Node* head = nullptr;

    // 테스트용 데이터 삽입
    head = push_front(head, 1);  // 1을 head로 삽입
    head = push_front(head, 2);  // 2를 head로 삽입
    head = pop_front(head);  // head 노드를 제거
    head = push_front(head, 3);  // 3을 head로 삽입
    head = push_front(head, 4);  // 4를 head로 삽입
    head = push_front(head, 5);  // 5를 head로 삽입
    head = pop_back(head);  // 마지막 노드 제거
    head = push_front(head, 6);  // 6을 head로 삽입

    display(head);  // 리스트 출력

    head = clear(head);  // 리스트 비우기
    display(head);  // 리스트 출력 (비어있어야 함)

    return 0;
}