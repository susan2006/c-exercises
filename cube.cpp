#include<iostream>
using namespace std;
void cube(int*);

int main(){
    int x;
    cout<<"Enter the number to be cubed: ";
    cin>>x;

    cube(&x);
    cout<<"The cube of the entered number is: "<<x;
    return 0;
}

void cube(int*n){
    *n = *n * *n * *n;
}