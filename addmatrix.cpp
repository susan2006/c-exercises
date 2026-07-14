#include<iostream>
#define N 3

using namespace std;

void addition(int a[][10], int b[][10], int s[][10]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            s[i][j] = a[i][j] + b[i][j];
    }
}

int main(){
    int a[10][10], b[10][10], s[10][10], i, j;

    cout<<"Enter values for matrix a: "<<endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            cin>>a[i][j];
    }

    cout<<"Enter values for matrix b: "<<endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            cin>>b[i][j];
    }

    addition(a,b,s);

    cout<<"Addition of 2 matrices is: "<<endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            cout<<s[i][j]<<"  ";
        cout<<endl;
    }
}
