#include <iostream>
using namespace std;

struct elem{
    int value;
};

class MyStack{
private:
    int size;
    int top;
    elem *list;

public:
    MyStack(int);
    ~MyStack(){ delete[] list; };
    void initialize();
    void push(const elem& pop);
    elem* pop();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;
} ;