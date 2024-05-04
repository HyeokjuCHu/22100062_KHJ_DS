#include <iostream>
#include <string>

using namespace std;

struct Elem
{
    int place;
    string name;
};

class CouponStack
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
    CouponStack(int size = 10);
    ~CouponStack()
    {
        delete[] list;
    };
    void print();
    void rprint();
};

CouponStack::CouponStack(int size)
{
    maxsize = size;
    list = new Elem[size];
    initialize();
}

void CouponStack::initialize()
{
    top = 0;
}

bool CouponStack::isEmpty()
{
    return (top == 0) ? true : false;
}

bool CouponStack::isFull()
{
    return (top == maxsize) ? true : false;
}

void CouponStack::push(const Elem &e)
{
    if (isFull())
    {
        return;
    }
    list[top++] = e;
}

Elem *CouponStack::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }
    return &list[--top];
}

void CouponStack::print()
{
    for (int i = 0; i < top; i++)
    {
        cout << list[i].place << " " << list[i].name << endl;
    }
}

void CouponStack::rprint()
{
    cout << "Reversed print of stack:" << endl;
    while (!isEmpty())
    {
        Elem *p = pop();
        cout << p->place << " " << p->name << endl;
    }
}

int main()
{
    Elem one;
    Elem *p;

    int x;
    cin >> x;
    cin.ignore();
    CouponStack myStack(x);
    int i = 0;
    string a;

    while (i < x)
    {
        int y;
        string b;
        getline(cin, a);
        if (a.substr(0, 1) == "+")
        {
            y = stoi(a.substr(1));
            b = a.substr(3);
            one.place = y;
            one.name = b;
            myStack.push(one);
            i++;
        }
        else if (a == "-")
        {
            p = myStack.pop();
            if (p != nullptr)
                cout << p->place << "Place - " << p->name << endl;
        
        }
        else if (a == "q")
        {
            break;
        }
    }

    cin >> a;

    if (a == "print")
    {
        myStack.print();
    }
    else if (a == "rprint")
    {
        myStack.rprint();
    }

    return 0;
}
