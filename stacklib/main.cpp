#include <iostream>
#include "mystack.h"

using namespace std;

int main()
{
    elem one;
    MyStack s1(5);
    one.value = 10 ; s1.push(one);
    one.value = 20 ; s1.push(one);
    one.value = 30 ; s1.push(one);
    one.value = 40 ; s1.push(one);
    one.value = 50 ; s1.push(one);
    one.value = 60 ; s1.push(one);
    s1.print();
    cout << s1.pop()->value << endl;
    cout << s1.pop()->value << endl;
    s1.print();
    return 0;
}