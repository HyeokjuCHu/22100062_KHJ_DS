#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    MyCircularQueue queue(size);

    string command;
    while (true)
    {
        cin >> command;

        if (command == "q")
        {
            break;
        }
        else if (command == "en")
        {
            int value;
            cin >> value;
            queue.enqueue(value);
        }
        else if (command == "de")
        {
            queue.dequeue();
        }
        else if (command == "front")
        {
            cout << queue.Front() << endl;
        }
        else if (command == "rear")
        {
            cout << queue.Rear() << endl;
        }
        else if (command == "size")
        {
            cout << queue.size() << endl;
        }
        else if (command == "empty")
        {
            cout << queue.isEmpty() << endl;
        }
        else if (command == "print")
        {
            queue.print();
        }
        else
        {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
