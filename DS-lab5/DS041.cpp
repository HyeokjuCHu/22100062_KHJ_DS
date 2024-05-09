#include <iostream>
#include "linkedList.h"

using namespace std;




int main()
{
    MyLinkedStack mymy;
    string a;
    int x;

    while (a != "q")
    {
        cin>>a;
        if (a == "push")
        {
            cin >> x;
            mymy.push(x);
        }
        else if (a == "pop")
        {
            mymy.pop();
        }
        else if (a == "peek")
        {
            cout<<mymy.peek()<<endl;
        }
        else if (a == "print")
        {
            mymy.printAll();
        }
        else
        {
            mymy.initialize();
        }
    }
    return 0;
}