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
        return -1;
    } else {
        Node* ptr = front;
        front = front->link;
        int value = ptr->data;
        delete ptr;
        if (front == nullptr) {
            rear = nullptr;
        }
        return value;
    }
}

int LinkList::Front() const {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return -1;
    }
    return front->data;
}

int LinkList::Rear() const {
    if (isEmpty()) {
        cout << "Link is Empty" << endl;
        return -1;
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
    cout << "NULL" << endl;
}
