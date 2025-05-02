#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class SplayTree {
private:
    Node* root;

    Node* rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* splay(Node* root, int key) {
        if (!root || root->key == key) return root;

        Node *leftTreeMax = nullptr, *rightTreeMin = nullptr;
        Node *leftDummy = new Node(0), *rightDummy = new Node(0);
        leftTreeMax = leftDummy;
        rightTreeMin = rightDummy;

        while (root && root->key != key) {
            if (key < root->key) {
                if (!root->left) break;
                if (key < root->left->key) {
                    root = rotateRight(root);
                    if (!root->left) break;
                }
                rightTreeMin->left = root;
                rightTreeMin = root;
                root = root->left;
            } else {
                if (!root->right) break;
                if (key > root->right->key) {
                    root = rotateLeft(root);
                    if (!root->right) break;
                }
                leftTreeMax->right = root;
                leftTreeMax = root;
                root = root->right;
            }
        }

        leftTreeMax->right = root->left;
        rightTreeMin->left = root->right;
        root->left = leftDummy->right;
        root->right = rightDummy->left;
        delete leftDummy;
        delete rightDummy;
        return root;
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(int key) {
        if (!root) {
            root = new Node(key);
            return;
        }
        root = splay(root, key);
        if (root->key == key) return;

        Node* newNode = new Node(key);
        if (key < root->key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }
        root = newNode;
    }

    void remove(int key) {
        if (!root) return;
        root = splay(root, key);
        if (root->key != key) return;

        Node* temp;
        if (!root->left) {
            temp = root->right;
        } else {
            temp = splay(root->left, key);
            temp->right = root->right;
        }
        delete root;
        root = temp;
    }

    bool search(int key) {
        root = splay(root, key);
        return root && root->key == key;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    SplayTree tree;
    int choice, value;
    cout << "\nSplay Tree Operations:";
    cout << "\n1. Insert";
    cout << "\n2. Delete";
    cout << "\n3. Search";
    cout << "\n4. Display";
    cout << "\n5. Exit";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << "Inserted " << value << " into the tree.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.remove(value);
                cout << "Deleted " << value << " from the tree.\n";
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << value << " found in the tree.\n";
                } else {
                    cout << value << " not found in the tree.\n";
                }
                break;
            case 4:
                cout << "Tree (Inorder): ";
                tree.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}
