#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int data) : data(data), link(nullptr) {}
};

class LinkList {
private:
    Node* front;
    Node* rear;

public:
    LinkList() : front(nullptr), rear(nullptr) {}
    ~LinkList() { initialize(); }
    void initialize();
    bool isEmpty() const;
    void enqueue(const int& e);
    int dequeue();
    int Rear() const;
    int Front() const;
    void displayQueue() const;
};

#endif // LINKEDLIST_H
