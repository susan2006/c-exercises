#include<iostream>
using namespace std;
void swap(int*, int*);

int main(){
    int a, b;

    cout<<"Enter a & b: ";
    cin>>a>>b;
    cout<<"Before swapping"<<endl;
    cout<<"a is "<<a<<", b is "<<b<<endl;

    swap(&a,&b);

    cout<<"After swapping"<<endl;
    cout<<"a is "<<a<<", b is "<<b;
    return 0;
}

void swap(int*a, int*b){
    
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}