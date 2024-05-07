#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

public:
    Node(int a){
        data=a;
    };
};

class MyLinkedStack
{
    Node *stacktop;

public:
    void initialize();
    bool isEmpty() const;
    void push(const int &e);
    void pop();
    int peek() const;
    int getNodeCnt() const;
    MyLinkedStack();
    ~MyLinkedStack();
    void printAll();

};

int main()
{

    return 0;
}