#include <iostream>

using namespace std;

typedef int Elem;

class MyCircularQueue
{
private:
    int maxsize;
    int front;
    int rear;
    Elem *list;

public:
    MyCircularQueue(int size);
    ~MyCircularQueue() { delete[] list; }

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const Elem &e);
    void dequeue();
    Elem Front() const;
    Elem Rear() const;
    void print() const;
    int size() const;
    void printDetail() const;
};