#include <iostream>
using namespace std;

class D {
public:
	~D(){
        cout <<"D";
    } // destructor
};
class C {
public:
	~C(){
        cout <<"C";
    } // destructor
};
class B {
public:
	~B(){
        cout <<"B";
    } // destructor
};
class A : public D, public virtual B, public C{
public:
	~A(){
        cout <<"A";
    } // destructor
};
int main(){
    A ob;
    return 0;
}