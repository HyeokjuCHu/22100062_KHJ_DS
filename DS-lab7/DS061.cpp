#include <iostream>
#include "linkedlist.h"

using namespace std;




int main()
{
    LinkList queue;
    int choice, value;
    do
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Show Front\n";
        cout << "4. Show Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a Value: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            cout << "Element at Front: " << queue.Front() << endl;
            break;
        case 4:
            cout << "Element at Rear: " << queue.Rear() << endl;
            break;
        case 5:
            cout << "Queue: ";
            queue.displayQueue();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
