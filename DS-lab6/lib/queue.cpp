#include "queue.h"

MyCircularQueue::MyCircularQueue(int size)
{
    maxsize = size + 1;
    front = 0;
    rear = 0;
    list = new Elem[maxsize];
}

void MyCircularQueue::initialize()
{
    front = 0;
    rear = 0;
    delete[] list;
    list = new Elem[maxsize];
}

bool MyCircularQueue::isEmpty() const
{
    return front == rear;
}

bool MyCircularQueue::isFull() const
{
    return (rear + 1) % maxsize == front;
}

void MyCircularQueue::enqueue(const Elem &e)
{
    if (!isFull())
    {
        list[rear] = e;
        rear = (rear + 1) % maxsize;
    }
    else
    {
        cout << "=> Queue is full ! " << endl;
    }
}

void MyCircularQueue::dequeue()
{
    if (!isEmpty())
    {
        front = (front + 1) % maxsize;
    }
    else
    {
        cout << "=> Queue is empty !" << endl;
    }
}

Elem MyCircularQueue::Front() const
{
    if (isEmpty())
    {
        cout << "=> Queue is empty !" << endl;
        return -1;
    }
    return list[front];
}

Elem MyCircularQueue::Rear() const
{
    if (isEmpty())
    {
        cout << "=> Queue is empty !" << endl;
        return -1;
    }
    return list[(rear - 1 + maxsize) % maxsize];
}

void MyCircularQueue::print() const
{
    if (!isEmpty())
    {
        int i = front;
        while (i != rear)
        {
            cout << "[" << list[i] << "]";
            i = (i + 1) % maxsize;
        }
        cout << endl;
    }
    else
    {
        cout << endl;
    }
}

int MyCircularQueue::size() const
{
    return (rear - front + maxsize) % maxsize;
}

void MyCircularQueue::printDetail() const
{
    cout << "Size : " << size() << endl;
    cout << "Queue : ";
    print();

    cout << "index : ";
    if (!isEmpty())
    {
        int i = front;
        while (i != rear)
        {
            cout << i << " ";
            i = (i + 1) % maxsize;
        }
    }
    cout << endl;
    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;
}


