#include<iostream>
using namespace std;
int main(){
    int first = 0, second = 1, sum = 0, n, i = 0;

    cout<<"Enter the term upto which it should be printed: ";

    cin>>n;

    cout<<"Fibonacci series upto "<<n<<" is: "<<endl;

    while(i<=n){
        cout<<sum<<endl;

        first = second;
        
        second = sum;
        
        sum = first + second;
        
        i++;
    }
    
}