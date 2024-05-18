#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Student
{
    float gpa;
    string name;
};

class MyCircularQueue
{
private:
    int maxsize;
    int front;
    int rear;
    Student *list;
    float maxGPA;

public:
    MyCircularQueue(int size = 10);
    ~MyCircularQueue() { delete[] list; }

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const Student &s);
    Student dequeue();
    void print() const;
    void processFile(const string &filename);
};

MyCircularQueue::MyCircularQueue(int size)
{
    maxsize = size + 1;
    front = 0;
    rear = 0;
    list = new Student[maxsize];
    maxGPA = 0.0f;
}

void MyCircularQueue::initialize()
{
    front = 0;
    rear = 0;
    delete[] list;
    list = new Student[maxsize];
    maxGPA = 0.0f;
}

bool MyCircularQueue::isEmpty() const
{
    return front == rear;
}

bool MyCircularQueue::isFull() const
{
    return (rear + 1) % maxsize == front;
}

void MyCircularQueue::enqueue(const Student &s)
{
    if (isFull())
    {
        cerr << "Queue is full!" << endl;
        return;
    }
    list[rear] = s;
    rear = (rear + 1) % maxsize;
    if (s.gpa > maxGPA)
    {
        maxGPA = s.gpa;
    }
}

Student MyCircularQueue::dequeue()
{
    if (isEmpty())
    {
        cerr << "Queue is empty!" << endl;
        return Student{-1.0f, ""}; // Return a default Student
    }
    Student s = list[front];
    front = (front + 1) % maxsize;
    return s;
}

void MyCircularQueue::print() const
{
    cout << "Top GPA: " << maxGPA << endl;
    if (!isEmpty())
    {
        int i = front;
        while (i != rear)
        {
            if (list[i].gpa == maxGPA)
            {
                cout << list[i].name << endl;
            }
            i = (i + 1) % maxsize;
        }
    }
}

void MyCircularQueue::processFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        float gpa;
        string name;
        istringstream iss(line);
        if (!(iss >> gpa >> name))
        {
            cerr << "Error reading line from file" << endl;
            continue;
        }
        Student s = {gpa, name};
        enqueue(s);
    }
    file.close();
}

int main()
{
    MyCircularQueue myQueue;

    // Replace "GPA.txt" with your actual file name
    myQueue.processFile("GPA.txt");

    myQueue.print();

    return 0;
}
