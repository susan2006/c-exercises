#include <iostream>
using namespace std;

int main() {
    int x, i, j, f;
    
    cout << "Enter the range number to print the prime numbers: ";
    cin >> x;
    
    cout << "The prime numbers between 1 and " << x << " are:\n";
 
    for (i = 1; i <= x; i++) {
        
        // They are niether prime nor composite if as skip 0 and 1
        if (i == 1 || i == 0) {
            continue;
        }
        
        f = 1;
 
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
 
        // f = 1 means i is prime and f = 0 means i is not prime
        if (f == 1) {
            cout << " " << i;
        }
    }
    return 0;
}