#include<iostream>
using namespace std;

int main(){
    int array[]{5,48,23,65,91,47}, i, sum = 0;
    int *aptr = array;

    int length = sizeof(array) / sizeof(array[0]);

    for(i=0;i<length;i++){
        sum += *(aptr+i);
    }

    cout<<"The sum of array elements is: "<<sum;
}