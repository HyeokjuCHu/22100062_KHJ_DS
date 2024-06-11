#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *start = nullptr;
Node *last = nullptr;

void swapNode(Node *x, Node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int y)
{
    Node *newNode = createNode(y);
    if (start == nullptr)
    {
        start = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void printLinked()
{
    Node *temp = start;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}

void clearLinked()
{
    Node *temp;
    while (start != nullptr)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
    start = nullptr;
    last = nullptr;
}

void init(int size)
{
    int number;
    clearLinked();
    std::cout << "Enter numbers... ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        addLast(number);
    }
}

void selectionLinked()
{
    Node *key;
    Node *temp;

    key = start;
    while (key != nullptr)
    {
        temp = key->next;
        while (temp != nullptr)
        {
            if (key->data > temp->data)
                swapNode(key, temp);
            temp = temp->next;
        }
        key = key->next;
    }
}

int main()
{
    int choice;
    while (true)
    {
        std::cout << "\n How many numbers do you want to create (0:exit) ... ";
        std::cin >> choice;
        if (choice == 0)
            break;
        init(choice);
        selectionLinked();
        printLinked();
    }
    return 0;
}
