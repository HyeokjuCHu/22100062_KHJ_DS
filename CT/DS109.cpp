#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;

        for (char c : s) {
            if (!stack.empty() && stack.top() == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    string output = solution.removeDuplicates(input);
    cout << "Result: " << output << endl;
    return 0;
}
