#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    vector<int> alphabetCount(26, 0);
    int countB=0;

    for (char c : input) {
        if (isalpha(c)) {
            c = tolower(c);
            alphabetCount[c - 'a']++;
        }else{
            countB++;
        }
    }

    cout<<"blanks : "<<countB<<endl;

    // 결과 출력
    for (int i = 0; i < 26; ++i) {
        if (alphabetCount[i] > 0) {
            char alphabet = 'A' + i;
            cout << alphabet << ": " << alphabetCount[i] << endl;
        }
    }

    return 0;
}
