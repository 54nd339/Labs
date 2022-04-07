#include <iostream>
using namespace std;
class Parent1{
    public:
    Parent1(){
        cout << "Inside first base class" << endl;
    }
    ~Parent1(){
        cout << "Parent1 class Destructor" << endl;
    }
};
 
class Parent2 : public Parent1{
    public:
    Parent2(){
        cout << "Inside second base class" << endl;
    }
    ~Parent2(){
        cout << "Parent2 class Destructor" << endl;
    }
};
 
class Child : public Parent2{
    public:
    Child(){
        cout << "Inside child class" << endl;
    }
    ~Child(){
        cout << "Child class Destructor" << endl;
    }
};

int main() {
    Child obj;
    return 0;
}