#include<iostream>
using namespace std;

class Add {
    public:
        static int Total;
        int x, y;
        int total() {
            Total += x + y;
            return Total;
        }
};

int Add::Total = 0;

int main() {
    Add a1, a2;
    a1.x = 3; a1.y = 4;
    cout << "Total of a1 is: " << a1.total() << endl;
    
    a1.x = 6; a1.y = 2;
    cout << "Total of a1 is: " << a1.total() << endl;
    
    return 0;
}
