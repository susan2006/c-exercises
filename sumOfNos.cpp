#include<iostream>
using namespace std;
int main()
{
    int no, i, sum=0;

    cout<<"Enter the value: ";

    cin>>no;
    
    for(i=1;i<=no;i++){
        sum += i;
    }
    
    cout<<"The sum upto "<<no<<" is "<<sum;
}