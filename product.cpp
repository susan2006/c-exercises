#include <iostream>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }

    void display() {
        cout << "Product: " << name << ", Price: " << price << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product* products = new Product[n];

    for (int i = 0; i < n; i++) {
        string name;
        double price;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter product price: ";
        cin >> price;
        products[i] = Product(name, price);
    }

    cout << "\nProduct Information:\n";
    for (int i = 0; i < n; i++) {
        products[i].display();
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += products[i].price;
    }

    cout << "\nTotal price: " << sum << endl;

    delete[] products;

    return 0;
}