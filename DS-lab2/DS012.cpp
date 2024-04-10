#include <iostream>

using namespace std;

void toLowerCase(string& str) {
    for (char& ch : str) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32; 
        }
    }
}


bool isEqual(string x, string y, int a, int b) {
    toLowerCase(x);
    toLowerCase(y);

    if(x==y&&a==b)return true;
    else return false;
}


struct Hi {
    string product;
    int price;
    string manuf;
};

int main() {
    Hi arr[2];

    
    for (int i = 0; i < 2; ++i) {
        cin >> arr[i].product >> arr[i].price >> arr[i].manuf;
    }

    
    if (isEqual(arr[0].product, arr[1].product,arr[0].price,arr[1].price)) {
        cout << arr[0].product << " is equal" << endl;
    } else {
        cout << arr[0].product << " and " << arr[1].product << " is not equal" << endl;
    }

    return 0;
}



//Hi arr[10];
//arr[i].name
//erference 배열?
