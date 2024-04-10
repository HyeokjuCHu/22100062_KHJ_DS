#include <iostream>

using namespace std;

struct Menu {
    string name;
    int price;
};

struct Cafe {
    string name;
    int msize;
    Menu* list;
};

void addCafe(Cafe& c) {
    getline(cin, c.name);
    cin >> c.msize;
    c.list = new Menu[c.msize];
    cin.ignore();

    for (int i = 0; i < c.msize; ++i) {
        cin >> c.list[i].name>>c.list[i].price;
        cin.ignore();
    }
}

void displayMenus(const Cafe& c) {
    cout << "=====" << c.name << "=====" << endl;
    for (int i = 0; i < c.msize; ++i) {
        cout << c.list[i].name << " " << c.list[i].price << endl;
    }
    cout<<"==============="<<endl;
}

int main() {
    Cafe c;

    addCafe(c);
    displayMenus(c);

    delete[] c.list;

    return 0;
}