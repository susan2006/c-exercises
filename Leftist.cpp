#include <bits/stdc++.h>
using namespace std;

class LeftistNode
{
public:
int element;
LeftistNode *left;
LeftistNode *right;
int dist;

LeftistNode(int &element, LeftistNode *lt = NULL,
LeftistNode *rt = NULL, int np = 0)
{
this->element = element;
left = lt;
right = rt;
dist = np;
}
};

class LeftistHeap
{
public:
LeftistHeap();
LeftistHeap(LeftistHeap &rhs);
~LeftistHeap();
bool isEmpty();
bool isFull();
int &findMin();
void Insert(int &x);
void deleteMin();
void deleteMin(int &minItem);
void makeEmpty();
void Merge(LeftistHeap &rhs);
LeftistHeap &operator=(LeftistHeap &rhs);
void printHeap(); // Print function

private:
LeftistNode *root;
LeftistNode *Merge(LeftistNode *h1, LeftistNode *h2);
LeftistNode *Merge1(LeftistNode *h1, LeftistNode *h2);
void swapChildren(LeftistNode *t);
void reclaimMemory(LeftistNode *t);
LeftistNode *clone(LeftistNode *t);
void levelOrderTraversal(LeftistNode *t); // Helper for print
};

LeftistHeap::LeftistHeap()
{
root = NULL;
}

LeftistHeap::LeftistHeap(LeftistHeap &rhs)
{
root = NULL;
*this = rhs;
}

LeftistHeap::~LeftistHeap()
{
makeEmpty();
}

void LeftistHeap::Merge(LeftistHeap &rhs)
{
if (this == &rhs)
return;
root = Merge(root, rhs.root);
rhs.root = NULL;
}

LeftistNode *LeftistHeap::Merge(LeftistNode *h1, LeftistNode *h2)
{
if (h1 == NULL)
return h2;
if (h2 == NULL)
return h1;
if (h1->element < h2->element)
return Merge1(h1, h2);
else
return Merge1(h2, h1);
}

LeftistNode *LeftistHeap::Merge1(LeftistNode *h1, LeftistNode *h2)
{
if (h1->left == NULL)
h1->left = h2;
else
{
h1->right = Merge(h1->right, h2);
if (h1->left->dist < h1->right->dist)
swapChildren(h1);
h1->dist = h1->right->dist + 1;
}
return h1;
}

void LeftistHeap::swapChildren(LeftistNode *t)
{
LeftistNode *tmp = t->left;
t->left = t->right;
t->right = tmp;
}

void LeftistHeap::Insert(int &x)
{
root = Merge(new LeftistNode(x), root);
}

int &LeftistHeap::findMin()
{
return root->element;
}

void LeftistHeap::deleteMin()
{
if (isEmpty())
{
cout << "Heap is empty, cannot delete!" << endl;
return;
}
LeftistNode *oldRoot = root;
root = Merge(root->left, root->right);
delete oldRoot;
}

void LeftistHeap::deleteMin(int &minItem)
{
if (isEmpty())
{
cout << "Heap is Empty" << endl;
return;
}
minItem = findMin();
deleteMin();
}

bool LeftistHeap::isEmpty()
{
return root == NULL;
}

bool LeftistHeap::isFull()
{
return false;
}

void LeftistHeap::makeEmpty()
{
reclaimMemory(root);
root = NULL;
}

LeftistHeap &LeftistHeap::operator=(LeftistHeap &rhs)
{
if (this != &rhs)
{
makeEmpty();
root = clone(rhs.root);
}
return *this;
}

void LeftistHeap::reclaimMemory(LeftistNode *t)
{
if (t != NULL)
{
reclaimMemory(t->left);
reclaimMemory(t->right);
delete t;
}
}

LeftistNode *LeftistHeap::clone(LeftistNode *t)
{
if (t == NULL)
return NULL;
else
return new LeftistNode(t->element, clone(t->left),
  clone(t->right), t->dist);
}

void LeftistHeap::levelOrderTraversal(LeftistNode *t)
{
if (t == NULL)
{
cout << "Heap is empty." << endl;
return;
}

queue<LeftistNode *> q;
q.push(t);

while (!q.empty())
{
LeftistNode *current = q.front();
q.pop();
cout << current->element << " ";

if (current->left)
q.push(current->left);
if (current->right)
q.push(current->right);
}
cout << endl;
}
// Public print function
void LeftistHeap::printHeap()
{
cout << "Heap elements (Level order): ";
levelOrderTraversal(root);
}

void menu()
{
LeftistHeap h1, h2;
int choice, element, minItem;
cout << "\nLeftist Heap Menu:\n";
cout << "1. Insert into Heap 1\n";
cout << "2. Insert into Heap 2\n";
cout << "3. Find Minimum (Heap 1)\n";
cout << "4. Delete Minimum (Heap 1)\n";
cout << "5. Merge Heap 2 into Heap 1\n";
cout << "6. Print Heap 1\n";
cout << "7. Print Heap 2\n";
cout << "8. Exit\n";

while (true)
{
cout << "Enter choice: ";
cin >> choice;

switch (choice)
{
case 1:
cout << "Enter element to insert in Heap 1: ";
cin >> element;
h1.Insert(element);
break;
case 2:
cout << "Enter element to insert in Heap 2: ";
cin >> element;
h2.Insert(element);
break;
case 3:
if (h1.isEmpty())
cout << "Heap 1 is empty.\n";
else
cout << "Minimum element in Heap 1: " << h1.findMin() << endl;
break;
case 4:
if (h1.isEmpty())
cout << "Heap 1 is empty.\n";
else
{
h1.deleteMin(minItem);
cout << "Deleted minimum element: " << minItem << endl;
}
break;
case 5:
h1.Merge(h2);
cout << "Heaps merged! Heap 2 is now empty.\n";
break;
case 6:
h1.printHeap();
break;
case 7:
h2.printHeap();
break;
case 8:
cout << "Exiting program.\n";
return;
default:
cout << "Invalid choice! Try again.\n";
}
}
}

int main()
{
menu();
return 0;
}
