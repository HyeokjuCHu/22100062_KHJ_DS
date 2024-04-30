#include <iostream>
#include <string>

using namespace std;

struct Elem
{
    int value;
};

class MyStack
{
private:
    int maxsize;
    int top;
    Elem *list;

public:
    void initialize();
    bool isEmpty();
    bool isFull();
    void push(const Elem &e);
    Elem *pop();
    MyStack(int size = 10);
    ~MyStack()
    {
        delete[] list;
    };
    void print();
};

MyStack::MyStack(int size)
{
    maxsize = size;
    list = new Elem[size];
    initialize();
}

void MyStack::initialize()
{
    top = 0;
}

bool MyStack::isEmpty()
{
    return (top == 0) ? true : false;
}

bool MyStack::isFull()
{
    return (top == maxsize) ? true : false;
}

void MyStack::push(const Elem &e)
{
    if (isFull())
    {
        return;
    }
    list[top++] = e;
}

Elem *MyStack::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }
    return &list[--top];
}

void MyStack::print()
{
    for (int i = 0; i < top; i++)
    {
        cout << list[i].value << endl;
    }
}

int main()
{
    Elem one;
    Elem *p;

    int x;
    cin >> x;
    MyStack myStack(x);
    int i=0;
    string a;
    while(i<x){
        int x;
        cin>>a;
        if(a=="push"){
            cin>>x;
            one.value=x;
            myStack.push(one);
            i++;  
        }else if(a=="pop"){
            myStack.pop();
        }
    }
    cin>>a;
    if(a=="print"){
        myStack.print();
    }   
    return 0;
}