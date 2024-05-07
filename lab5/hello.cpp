//time start: 14:20 ~ 34
#include <iostream>
using namespace std;

struct Element
{
    int rank;
    string ProductName;
};

//This class is for Stack
class MyStack{
    private:
        int maxsize;    //maximum size of Stack
        int top;    //show current position of stack
        Element *list;  //value in the stack
    public:
        void initialize();  //setting top to 0
        bool isEmpty() const;   //checking if stack is empty
        bool isFull() const;    //checking if stack is full
        void push(const Element& e);    //push the value into the stack
        Element* pop(); //pop the element from the stack
        MyStack(int size= 10);  //constructor of class
        ~MyStack() {    //deconstructor
            delete[] list;
        };
        void print();   //print current situation of stack
        void rprint();   //print stack in order
};

//This is Constructor which sets stack
MyStack::MyStack(int size){
    maxsize = size;
    list = new Element[size];
    initialize();
}

//This sets top as 0
void MyStack::initialize(){
    top = 0;
}

//if it is empty returns true
bool MyStack::isEmpty() const{
    return (top==0);
}

//if stack is full it returns true
bool MyStack::isFull() const{
    return (top==maxsize);
}

//push into the stack
void MyStack::push(const Element& e){
    if (isFull()) return;
    list[top++] = e; 
}

//pop from the stack
Element* MyStack::pop(){
    if(isEmpty()) return nullptr;
    return &list[--top];
}

//print out current situation of stack
void MyStack::print(){
    for(int i=0;i<top;i++){
        cout << list[i].rank << list[i].ProductName << endl;
    }
}

void MyStack::rprint()
{
    for (int i = top; i >=0; i--)
    {
        cout << list[i].rank << list[i].ProductName << endl;
    }
}

int main(void){
    int n;
    cin >> n;
    MyStack myStack(n);
    Element one;
    Element* e;
    while(1){
        char option;
        cin >> option;
        if (option == '+'){
            cin >> one.rank;
            cin.ignore();
            getline(cin, one.ProductName);
            myStack.push(one);
        } else if(option == '-'){
            e = myStack.pop();
            if (e != nullptr)
            {
                cout << e->rank << " 등 - " << e->ProductName << endl;
                delete e;
            }
            else
            {
                cout << "Stack is Empty." << endl;
            }
        } else if (option == 'q') {
            break;
        }   
    }

}