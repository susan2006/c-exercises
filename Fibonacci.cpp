#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <climits>

using namespace std;

// Node structure for Fibonacci Heap
struct Node {
    int key;
    int degree;
    bool mark;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        degree = 0;
        mark = false;
        parent = child = nullptr;
        left = right = this;
    }
};

// Fibonacci Heap class
class FibonacciHeap {
private:
    Node* min;
    int nodeCount;

    // Link two nodes during consolidation
    void linkNodes(Node* child, Node* parent) {
        child->left->right = child->right;
        child->right->left = child->left;

        child->parent = parent;
        parent->degree++;

        if (parent->child == nullptr) {
            parent->child = child;
            child->right = child;
            child->left = child;
        } else {
            child->right = parent->child->right;
            child->left = parent->child;
            parent->child->right->left = child;
            parent->child->right = child;
        }
        child->mark = false;
    }

    // Consolidate trees after extract-min
    void consolidate() {
        int maxDegree = static_cast<int>(log2(nodeCount)) + 1;
        vector<Node*> degreeTable(maxDegree, nullptr);

        list<Node*> rootList;
        Node* current = min;
        if (current != nullptr) {
            do {
                rootList.push_back(current);
                current = current->right;
            } while (current != min);
        }

        for (Node* w : rootList) {
            Node* x = w;
            int d = x->degree;

            while (degreeTable[d] != nullptr) {
                Node* y = degreeTable[d];
                if (x->key > y->key) {
                    swap(x, y);
                }
                linkNodes(y, x);
                degreeTable[d] = nullptr;
                d++;
            }
            degreeTable[d] = x;
        }

        min = nullptr;
        for (Node* node : degreeTable) {
            if (node != nullptr) {
                if (min == nullptr) {
                    min = node;
                    min->left = min;
                    min->right = min;
                } else {
                    node->right = min->right;
                    node->left = min;
                    min->right->left = node;
                    min->right = node;
                    if (node->key < min->key) {
                        min = node;
                    }
                }
            }
        }
    }

    // Cut a node from its parent and add to root list
    void cut(Node* x, Node* parent) {
        parent->degree--;
        if (x == x->right) {
            parent->child = nullptr;
        } else {
            parent->child = x->right;
        }
        x->left->right = x->right;
        x->right->left = x->left;

        x->parent = nullptr;
        x->mark = false;

        x->right = min->right;
        x->left = min;
        min->right->left = x;
        min->right = x;
    }

    // Cascading cut when a marked node loses a child
    void cascadingCut(Node* y) {
        Node* z = y->parent;
        if (z != nullptr) {
            if (!y->mark) {
                y->mark = true;
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    // Recursive search for a key in Fibonacci Heap
    Node* searchRecursive(Node* start, int key) {
        if (start == nullptr) return nullptr;
        Node* temp = start;
        do {
            if (temp->key == key) return temp;
            if (temp->child) {
                Node* found = searchRecursive(temp->child, key);
                if (found) return found;
            }
            temp = temp->right;
        } while (temp != start);
        return nullptr;
    }

public:
    FibonacciHeap() {
        min = nullptr;
        nodeCount = 0;
    }

    // Insert a new key
    Node* insert(int key) {
        Node* node = new Node(key);
        nodeCount++;

        if (min == nullptr) {
            min = node;
        } else {
            node->right = min->right;
            node->left = min;
            min->right->left = node;
            min->right = node;
            if (node->key < min->key) {
                min = node;
            }
        }
        return node;
    }

    // Extract minimum node
    int extractMin() {
        if (min == nullptr) return -1;

        Node* z = min;
        int minKey = z->key;

        if (z->child != nullptr) {
            Node* child = z->child;
            do {
                Node* next = child->right;
                child->parent = nullptr;
                child->right = min->right;
                child->left = min;
                min->right->left = child;
                min->right = child;
                child = next;
            } while (child != z->child);
        }

        z->left->right = z->right;
        z->right->left = z->left;

        if (z == z->right) {
            min = nullptr;
        } else {
            min = z->right;
            consolidate();
        }

        nodeCount--;
        delete z;
        return minKey;
    }

    // Search for a key
    Node* search(int key) {
        return searchRecursive(min, key);
    }

    // Decrease key of a node
    void decreaseKey(Node* x, int newKey) {
        if (!x || newKey > x->key) return;

        x->key = newKey;
        Node* y = x->parent;

        if (y != nullptr && x->key < y->key) {
            cut(x, y);
            cascadingCut(y);
        }

        if (x->key < min->key) {
            min = x;
        }
    }

    // Remove a node
    void remove(int key) {
        Node* node = search(key);
        if (!node) return;

        decreaseKey(node, INT_MIN);
        extractMin();
    }

    // Display the heap
    void display() {
        if (min == nullptr) {
            cout << "Heap is empty" << endl;
            return;
        }
        cout << "Fibonacci Heap (root list): ";
        Node* current = min;
        do {
            cout << current->key << " ";
            current = current->right;
        } while (current != min);
        cout << endl;
    }
};

// Main function to test Fibonacci Heap
int main() {
    FibonacciHeap fh;

    Node* node1 = fh.insert(10);
    fh.insert(5);
    fh.insert(15);
    fh.insert(2);
    fh.insert(8);
    fh.display();

    cout << "Extracting min: " << fh.extractMin() << endl;
    fh.display();

    cout << "Decreasing 10 to 3" << endl;
    fh.decreaseKey(node1, 3);
    fh.display();

    cout << "Removing 3" << endl;
    fh.remove(3);
    fh.display();

    return 0;
}
