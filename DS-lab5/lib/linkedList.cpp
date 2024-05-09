#include "linkedList.h"

MyLinkedStack::MyLinkedStack()
{
    stacktop = NULL;
}
bool MyLinkedStack::isEmpty() const
{
    if (stacktop == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyLinkedStack::pop()
{
    if (isEmpty())
    {
        return;
    }

    Node *temp = stacktop;
    stacktop = stacktop->next;
    delete temp;
}

void MyLinkedStack::push(const int &e)
{
    Node *temp = new Node(e);
    temp->next = stacktop;
    stacktop = temp;
}

void MyLinkedStack::initialize()
{
    if (isEmpty())
    {
        return;
    }

    while (!isEmpty())
    {
        pop();
    }
}

int MyLinkedStack::peek() const
{
    if (isEmpty())
    {
        return -1;
    }
    
    return stacktop->data;
}

int MyLinkedStack::getNodeCnt() const
{
    int count = 0;
    Node *current = stacktop;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void MyLinkedStack::printAll()
{
    Node *current = stacktop;
    if (current == nullptr)
    {
        cout << "Stack is empty" << endl;
        cout << "Bye!" << endl;
    }
    else
    {
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " (" << getNodeCnt() << " nodes)" << endl;
    }
}