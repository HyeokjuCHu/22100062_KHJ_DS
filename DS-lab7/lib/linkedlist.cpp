#include "linkedlist.h"

bool LinkList::isEmpty() const
{
    return (front == nullptr);
}

void LinkList::dequeue()
{
    if (isEmpty())
    {
        cout << "Link is Empty" << endl;
    }
    else if (front->link == nullptr)
    {
        delete front;
        front = nullptr;
        rear = nullptr;
    }
    else
    {
        Node *ptr = front;
        front = front->link;
        delete ptr;
    }
}

void LinkList::initialize()
{
    while (front != nullptr)
    {
        Node *ptr = front;
        front = front->link;
        delete ptr;
    }
    rear = nullptr;
}

void LinkList::enqueue(const int &e)
{
    Node *ptr = new Node(e);
    if (isEmpty())
    {
        front = rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

int LinkList::Front() const
{
    if (isEmpty())
    {
        cout << "Link is Empty" << endl;
        return -1; // Assuming -1 represents an empty value
    }
    return front->data;
}

int LinkList::Rear() const
{
    if (isEmpty())
    {
        cout << "Link is Empty" << endl;
        return -1; // Assuming -1 represents an empty value
    }
    return rear->data;
}

void LinkList::displayQueue() const
{
    if (isEmpty())
    {
        cout << "Link is Empty" << endl;
        return;
    }
    Node *current = front;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->link;
    }
    cout << endl;
}
