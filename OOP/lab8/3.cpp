#include <iostream>
using namespace std;

class Base {
    string s;
    public:
    Base(){
        s = "Base";
    }
    void print() {
        cout << s+" Function" << endl;
    }
};

class Derived : public Base {
    string s;
    public:
    Derived(){
        s = "Derived";
    }
    void print() {
        cout << s+" Function" << endl;
    }
};

int main() {
    Derived derived1;
    derived1.print();
    derived1.Base::print();
    return 0;
}