#include <iostream>
#include "linkedList.h"

using namespace std;

bool is_operator(char c)
{
    return (c == '*' || c == '/' || c == '+' || c == '-');
}

int apply_operator(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else
        {
            cerr << "Division by zero\n";
            exit(1);
        }
    default:
        cerr << "Error: Invalid operator\n";
        exit(1);
    }
}

int main()
{
    MyLinkedStack myStack;
    string postfixExpression;
    getline(cin, postfixExpression);

    string num = "";
    int operandCount = 0;
    int operatorCount = 0;
    for (char c : postfixExpression)
    {
        if (isdigit(c))
        {
            num += c;
        }
        else if (c == ' ')
        {
            if (!num.empty())
            {
                myStack.push(stoi(num));
                num = "";
                operandCount++;
            }
        }
        else if (is_operator(c))
        {
            if (operandCount < 2)
            { // 피연산자가 충분하지 않은 경우
                cerr << "Too few operands" << endl;
                exit(1);
            }
            int operand2 = myStack.peek();
            myStack.pop();
            int operand1 = myStack.peek();
            myStack.pop();
            int result = apply_operator(operand1, operand2, c);
            myStack.push(result);
            operandCount--;
            operatorCount++;
        }
        else if (c == ';')
        {
            cerr << "Expression error!" << endl;
            exit(1);
        }
    }
    if (operandCount > 1 || operatorCount >= operandCount)
    {
        cerr << "Too many operators" << endl;
        exit(1);
    }
    else
    {
        if (!myStack.isEmpty())
        {
            int finalResult = myStack.peek();
            myStack.pop();
            cout << "Result: " << finalResult << endl;
        }
        else
        {
            cerr << "Error: Invalid postfix expression\n";
            exit(1);
        }
    }

    return 0;
}
