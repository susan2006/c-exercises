#include<iostream>
using namespace std;

class Operation{
    private: 
        int x,y;
    public:
        void get(){
            cout<<"Enter x & y:"<<endl;
            cin>>x>>y;
        }
        void sum(); void diff(); void prod(); void div();
};

inline void Operation::sum(){
    cout<<"Sum is: "<<x+y<<endl;
}
inline void Operation::diff(){
    cout<<"Sum is: "<<x-y<<endl;
}
inline void Operation::prod(){
    cout<<"Sum is: "<<x*y<<endl;
}
inline void Operation::div(){
    cout<<"Sum is: "<<x/y<<endl;
}

int main(){
    Operation o;
    o.get();
    o.sum();
    o.diff();
    o.prod();
    o.div();
    return 0;
}
