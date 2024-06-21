#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int score;
    string name;
    Node *next;
};

Node *start = nullptr;
Node *last = nullptr;

void swapNode(Node *x, Node *y)
{
    int tempScore = x->score;
    string tempName = x->name;
    x->score = y->score;
    x->name = y->name;
    y->score = tempScore;
    y->name = tempName;
}

Node *createNode(int score, string name)
{
    Node *newNode = new Node;
    newNode->score = score;
    newNode->name = name;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int score, string name)
{
    Node *newNode = createNode(score, name);
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
    int index = 1;
    while (temp != nullptr)
    {
        cout << index++ << "> " << temp->score << " " << temp->name << endl;
        temp = temp->next;
    }
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
    int score;
    string name;
    clearLinked();
    for (int i = 0; i < size; i++)
    {
        cin >> score;
        cin.ignore();
        getline(cin, name);
        addLast(score, name);
    }
}

void bubbleSortLinked()
{
    if (start == nullptr) return;
    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->score < ptr1->next->score)
            {
                swapNode(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main()
{
    int n;
    cin >> n;

    init(n);
    bubbleSortLinked();
    printLinked();

    return 0;
}
