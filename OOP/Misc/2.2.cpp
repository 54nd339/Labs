#include<iostream>
using namespace std;
class A{
    public: 
    A(){
        cout<<"contructor of class A"<<endl;
    }
    ~A(){
        cout<<"destructor of class A"<<endl;
    }
};
class B{
    public: 
    A obj;
    B(){
        cout<<"contructor of class B"<<endl;
    }
    ~B(){
        cout<<"destructor of class B"<<endl;
    }
};
int main(){
    B ob;
    return 0;
}
