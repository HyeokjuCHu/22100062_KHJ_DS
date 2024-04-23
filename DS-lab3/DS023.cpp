#include <iostream>

using namespace std;

class Product {
private:
    string name;
    int price;
    int disc;    // Discount percentage
    string manuf;
    int size;    // Size or capacity of the product

public:
    // Parameterized constructor
    Product(string n, int p, int d, string m, int s) 
        : name(n), price(p), disc(d), manuf(m), size(s) {}

    // Default constructor
    Product() 
        : name(""), price(0), disc(0), manuf(""), size(0) {}

    int getSalePrice() const {
        return price * (100 - disc) / 100;
    }

    string getName() const {
        return name;
    }

    int getSize() const {
        return size;
    }

    string getManufacturer() const {
        return manuf;
    }

    int getDiscount() const {
        return disc;
    }

    void display() const {
        cout << getSalePrice() << " (-" << disc << "%)\t" << name << " " << size << "g " << manuf << endl;
    }
};

int main() {
    const int MAX_PRODUCTS = 100;
    Product productList[MAX_PRODUCTS]; // This will now call the default constructor for each element
    int numProducts = 0;

    int choice = 0;

    while (choice != 3) {
        cout << "1. Add 2. List 3. Quit > ";
        cin >> choice;

        if (choice == 1) {
            if (numProducts < MAX_PRODUCTS) {
                string name, manuf;
                int price, disc, size;
                cin.ignore(); // Clear any pending newline characters
                getline(cin, name);
                cin >> price >> disc >> size;
                cin.ignore(); // Clear any pending newline characters
                getline(cin, manuf);

                productList[numProducts] = Product(name, price, disc, manuf, size);
                numProducts++;
            } else {
                cout << "Cannot add more products. Maximum limit reached." << endl;
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < numProducts; i++) {
                productList[i].display();
            }
        }
    }

    return 0;
}
