#include <iostream>

using namespace std;

int main() {
    int month,day;
    int day_count = 0;

    cin >> month>>day;

    for (int i = 1; i < month; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            day_count += 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            day_count += 30;
        } else if (i == 2) {
            day_count += 28;
        } 
    }

    cout <<day_count+day << endl;
    return 0;
}
