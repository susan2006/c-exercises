#include <iostream>
using namespace std;

class DynamicTable {
    int *table;
    int capacity, size;

    // Function to resize the table when needed
    void resize(int newCapacity) {
        int *ntable = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            ntable[i] = table[i];
        delete[] table;
        table = ntable;
        capacity = newCapacity;
        cout << "Resized the table to capacity: " << capacity << endl;
    }

public:
    DynamicTable(int icapacity = 2) {
        capacity = icapacity;
        size = 0;
        table = new int[capacity];
    }

    ~DynamicTable() {
        delete[] table;
    }

    void insert(int val) {
        int cost = 1;
        if (size == capacity) {
            resize(capacity * 2);
            cost = capacity;  // Resize cost
        }
        table[size] = val;
        size++;
        cout << "Inserted value: " << val
             << " | Cost: " << cost
             << " | Capacity: " << capacity << endl;
    }

    void remove() {
        if (size == 0) {
            cout << "Table is empty, nothing to delete!" << endl;
            return;
        }

        int cost = 1;
        size--;

        if (size > 0 && size <= capacity / 4) {
            resize(capacity / 2);
            cost = capacity;  // Resize cost
        }

        cout << "Deleted last value"
             << " | Cost: " << cost
             << " | Capacity: " << capacity << endl;
    }

    void display() {
        if (size == 0) {
            cout << "Table is empty!" << endl;
            return;
        }

        cout << "Dynamic table: ";
        for (int i = 0; i < size; ++i)
            cout << table[i] << " ";
        cout << "\nSize: " << size << " | Capacity: " << capacity << endl;
    }
};

int main() {
    DynamicTable d;
    int ch;

    cout << "Enter\n1 for inserting a value\n2 for deleting a value\n3 for displaying the table\n0 for exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int value;
                cout << "Enter a value to insert: ";
                cin >> value;
                d.insert(value);
                break;
            }
            case 2:
                d.remove();
                break;
            case 3:
                d.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (ch != 0);

    return 0;
}
