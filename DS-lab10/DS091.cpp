#include <iostream>
#include <string>
#include <stack>

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


string processInput(const string &input)
{
    stack<char> leftStack;
    stack<char> rightStack;

    for (char ch : input)
    {
        if (ch == '<')
        {
            if (!leftStack.empty())
            {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        }
        else if (ch == '>')
        {
            if (!rightStack.empty())
            {
                leftStack.push(rightStack.top());
                rightStack.pop();
            }
        }
        else
        {
            leftStack.push(ch);
        }
    }

    string result;
    while (!leftStack.empty())
    {
        result = leftStack.top() + result;
        leftStack.pop();
    }
    while (!rightStack.empty())
    {
        result += rightStack.top();
        rightStack.pop();
    }

    return result;
}

int main()
{
    string userInput;
    while (true)
    {
        getline(cin, userInput);

        if (userInput == "q")
        {
            break;
        }
        else
        {
            string resultString = processInput(userInput);
            cout << "=> " << resultString << endl;
        }
    }

    return 0;
}
