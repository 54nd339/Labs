#include <iostream>
using namespace std;
class Base{
    protected:
    int a;
    Base(){ a=3; }
};
class Child_11 : protected virtual Base{
    protected:
    int b;
    Child_11(){ b=4; }
};
class Child_12 : protected virtual Base{
    protected:
    int c;
    Child_12(){ c=5; }
};
class Child_2 : protected Child_11, protected Child_12{
    public:
    Child_2(){
        cout<< a << " "<< b << " "<< c << endl;
    }
};
int main(){
    Child_2 obj;
}