#include <iostream>
using namespace std;
void add(int n1, int n2)
{
    cout << "Addition of " << n1 << " & " << n2 << " is " << n1 + n2<<endl;
}
void sub(int n1, int n2)
{
    cout << "Subtraction of " << n1 << " & " << n2 << " is " << n1 - n2<<endl;
}
void mul(int n1, int n2)
{
    cout << "Multiplication of " << n1 << " & " << n2 << " is " << n1 * n2<<endl;
}

void division(int n1, int n2)
{
    cout << "Division of " << n1 << " & " << n2 << " is " << n1 / n2<<endl;
}
int main()
{
    int n1, n2;

    cout << "Enter n1 and n2 values:";

    cin >> n1 >> n2;

    add(n1, n2);

    sub(n1, n2);

    mul(n1, n2);

    division(n1, n2);

    return 0;
}
//Output is
//Enter n1 and n2 values:3 4
//Addition of 3 & 4 is 7
//Subtraction of 3 & 4 is -1
//Multiplication of 3 & 4 is 12
//Division of 3 & 4 is 0
