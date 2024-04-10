#include <iostream>
#include <string>

using namespace std;

string findCommonPrefix(const string& str1, const string& str2);
string findLongestCommonPrefix(const string strings[], int count);

int main() {
    const int numStrings = 3;
    string strings[numStrings];

    for (int i = 0; i < numStrings; ++i) {
        cin >> strings[i];
    }

    string commonPrefix = findLongestCommonPrefix(strings, numStrings);

    if (commonPrefix.empty()) {
        cout << "?\n";
    } else {
        cout << commonPrefix << '\n';
    }

    return 0;
}

string findCommonPrefix(const string& str1, const string& str2) {
    int minLength = min(str1.length(), str2.length());
    for (int i = 0; i < minLength; ++i) {
        if (str1[i] != str2[i]) {
            return str1.substr(0, i);
        }
    }
    return str1.substr(0, minLength);
}

string findLongestCommonPrefix(const string strings[], int count) {
    if (count == 0) {
        return "";
    }

    string prefix = strings[0];
    for (int i = 1; i < count; ++i) {
        prefix = findCommonPrefix(prefix, strings[i]);
        if (prefix.empty()) {
            break;
        }
    }
    return prefix;
}
