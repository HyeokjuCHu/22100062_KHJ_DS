#include <iostream>
#include <string>

using namespace std;

void ltrim(string& str) {
    size_t start = 0;
    while (start < str.length() && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }
    
    if (start < str.length()) {
        str = str.substr(start);
    } else {
        str = "";
    }
}

void rtrim(string& str) {
    size_t end = str.length() - 1;
    while (end >= 0 && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }
    
    if (end >= 0) {
        str = str.substr(0, end + 1);
    } else {
        str = "";
    }
}

int main() {
    string x;
    getline(cin, x);

    ltrim(x);
    rtrim(x);

    // 결과 출력
    cout << x  << endl;

    return 0;
}
