#include<iostream>
using namespace std;

class AreaSquare{
    public:
        int l;
        float a;
        friend void get(AreaSquare&); 
        friend void area(AreaSquare&);
};
void get(AreaSquare &obj){
    cout<<"Enter length of the square: ";
    cin>>obj.l;
}
void area(AreaSquare &obj){
    obj.a = obj.l * obj.l;
    cout<<"Area of square of length "<<obj.l<<" is: "<<obj.a;
}

int main(){
    AreaSquare a;
    get(a);
    area(a);
    return 0;
}