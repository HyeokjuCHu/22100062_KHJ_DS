#include <iostream>
#include "linkedlist.h"

using namespace std;

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1;
    int result = 0;

    LinkList fibList;
    fibList.enqueue(a);
    fibList.enqueue(b);

    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
        fibList.enqueue(result);
    }

    for (int i = 0; i <= n; ++i) {
        cout << i << "th: " << fibList.dequeue() << endl;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int fibN = fibonacci(n);
    cout << "=> fibonacci(" << n << "): " << fibN << endl;

    return 0;
}
