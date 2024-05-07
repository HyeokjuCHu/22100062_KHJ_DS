#include "mystack.h"

MyStack::MyStack(int s){
    size = s;
    initialize();
}

void MyStack::initialize(){
    top = 0;
    list = new elem[size];
}
bool MyStack::isEmpty() const{
    return (top == 0)? true : false;
}
bool MyStack::isFull() const{
    return (top == size)? true : false;
}

void MyStack::push(const elem& e){
    if(isFull()){
        //cout << "Cannot add to a full stack!" << endl;
        return;
    }
    list[top++] = e;
}

elem* MyStack::pop(){
    elem *ptr = nullptr;
    if(isEmpty()) return ptr;
    return &list[--top];
}

void MyStack::print() const {
    for(int i =0; i < top; i++){
        cout << list[i].value << endl;
    }
}