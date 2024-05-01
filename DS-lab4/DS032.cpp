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

class MyStack
{
private:
    int maxsize;
    int top;
    Student *list;
    float maxGPA;

public:
    MyStack(int size = 10);
    ~MyStack();
    void push(const Student &s);
    Student pop();
    void print();
    void processFile(const string &filename);
};

MyStack::MyStack(int size)
{
    maxsize = size;
    list = new Student[size];
    top = 0;
    maxGPA = 0.0f;
}

MyStack::~MyStack()
{
    delete[] list;
}

void MyStack::push(const Student &s)
{
    if (top >= maxsize)
    {
        cerr << "Stack overflow" << endl;
        return;
    }
    // 스택에 새로운 학생을 추가합니다.
    list[top++] = s;
    // 새로운 학생의 GPA가 최고 GPA보다 높은 경우, 최고 GPA를 업데이트합니다.
    if (s.gpa > maxGPA)
    {
        maxGPA = s.gpa;
    }
}

Student MyStack::pop()
{
    if (top <= 0)
    {
        cerr << "Stack underflow" << endl;
        return Student{-1.0f, ""}; // Return a default Student
    }
    return list[--top];
}

void MyStack::print()
{
    cout << "Top GPA: " << maxGPA << endl;
    for (int i = 0; i < top; i++)
    {
        if (list[i].gpa == maxGPA)
        {
            cout << list[i].name << endl;
        }
    }
}

void MyStack::processFile(const string &filename)
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
        // Extract GPA and name from the line
        if (!(iss >> gpa >> name))
        {
            cerr << "Error reading line from file" << endl;
            continue;
        }
        Student s = {gpa, name};
        push(s);
    }
    file.close();
}

int main()
{
    MyStack myStack;

    // Replace "GPA.txt" with your actual file name
    myStack.processFile("GPA.txt");

    myStack.print();

    return 0;
}
