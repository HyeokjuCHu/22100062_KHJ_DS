#include "linkedlist.h"

bool LinkList::isEmpty() const {
    return (front == nullptr);
}

void LinkList::initialize() {
    while (front != nullptr) {
        Node* ptr = front;
        front = front->link;
        delete ptr;
    }
    rear = nullptr;
}

void LinkList::enqueue(const int& e) {
    Node* ptr = new Node(e);
    if (isEmpty()) {
        front = rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

int LinkList::dequeue() {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return -1; // 빈 값을 나타내는 -1 반환
    } else if (front->link == nullptr) {
        int value = front->data;
        delete front;
        front = rear = nullptr;
        return value;
    } else {
        Node* ptr = front;
        front = front->link;
        int value = ptr->data;
        delete ptr;
        return value;
    }
}

int LinkList::Front() const {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return -1; // 빈 값을 나타내는 -1 반환
    }
    return front->data;
}

int LinkList::Rear() const {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return -1; // 빈 값을 나타내는 -1 반환
    }
    return rear->data;
}

void LinkList::displayQueue() const {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return;
    }
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->link;
    }
    cout << endl;
}
