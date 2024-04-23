#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string pcode;
    string pname;
    int cost;
    int leftN;
    int disc;

public:
    // Default constructor
    Product() : pcode(""), pname(""), cost(0), leftN(0), disc(0) {}

    // Constructor with parameters
    Product(string code, string name, int price, int left, int discount)
        : pcode(code), pname(name), cost(price), leftN(left), disc(discount) {}

    // Calculate sale price after discount
    int getSalePrice() const {
        return cost * (100 - disc) / 100;
    }

    // Display product details
    void display() const {
        cout << "[" << pcode << "] " << pname << " - Cost: " << cost << ", Sale Price: " << getSalePrice() << endl;
    }
};

int main() {
    int a;
    cout << "Enter the number of products: ";
    cin >> a;

    // Dynamically allocate array of Product objects
    Product* List = new Product[a];

    for (int i = 0; i < a; i++) {
        string name, code;
        int price, disc, left;
        cin.ignore(); // Clear any pending newline characters
        cout << "Enter product code: ";
        getline(cin, code);
        cout << "Enter product price, quantity left, discount percentage: ";
        cin >> price >> left >> disc;
        cin.ignore(); // Clear any pending newline characters
        cout << "Enter product name: ";
        getline(cin, name);

        // Create a new Product object and assign to List array
        List[i] = Product(code, name, price, left, disc);
    }

    cout << "\nProducts List:\n";
    for (int i = 0; i < a; i++) {
        List[i].display();
    }

    // Clean up: release dynamically allocated array
    delete[] List;

    return 0;
}
