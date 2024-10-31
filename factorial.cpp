#include <iostream>
using namespace std;

int factorial(int no)
{
    int facto = 1;

    while (no >= 1)
    {
        facto = facto * no;
        no--;
    }
    return facto;
}

int main()
{
    int no, fact;

    cout << "Enter a number: ";
    cin >> no;

    fact = factorial(no);
    
    cout << "Factorial of " << no << " is " << fact;
}