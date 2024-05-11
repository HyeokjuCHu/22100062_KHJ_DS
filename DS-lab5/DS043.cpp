#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    };
};



class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return '\0';
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return '\0';
        }
        return top->data;
    }
};

string processInput(const string& input) {
    LinkedListStack leftStack;
    LinkedListStack rightStack;

    for (char ch : input) {
        if (ch == '<') {
            if (!leftStack.isEmpty()) {
                rightStack.push(leftStack.pop());
            }
        } else if (ch == '>') {
            if (!rightStack.isEmpty()) {
                leftStack.push(rightStack.pop());
            }
        } else {
            leftStack.push(ch);
        }
    }

    string result;
    while (!leftStack.isEmpty()) {
        result = leftStack.pop() + result;
    }
    while (!rightStack.isEmpty()) {
        result += rightStack.pop();
    }

    return result;
}

int main() {
    string userInput;
    while (true) {
        getline(cin, userInput);

        if (userInput == "q") {
            break;
        } else {
            string resultString = processInput(userInput);
            cout << "=> " << resultString << endl;
        }
    }

    return 0;
}
