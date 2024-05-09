#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
};

class MyLinkedStack
{
private:
    Node *stacktop;

public:
    void initialize();
    bool isEmpty() const;
    void push(const int &e);
    void pop();
    int peek() const;       // 현재 stacktop에 있는 내용 출력(pop은 하지않음)
    int getNodeCnt() const; // node개수
    MyLinkedStack();
    ~MyLinkedStack()
    {
        while (!isEmpty())
            pop();
    }
    void printAll(); // stack을 pop순서로 출력.
};