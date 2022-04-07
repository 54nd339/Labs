#include <iostream>
using namespace std;
class complex{
    float real,imag;
    public:
    void display(){
        cout << real << " + " << imag << "i" << endl;
    }
    complex(){
        cout << "\nDefault Constructor called";
        cout << "\nEnter the terms in the complex : ";
        cin >> real >> imag; this->display();
    }
    complex(float r, float i){
        cout << "Parameterized Constructor called\n";
        real = r; imag = i; this->display();
    }
    complex(complex &c){
        cout << "\nCopy Constructor called\n";
        real = c.real; imag = c.imag; this->display();
    }
    ~complex(){
        cout << "\nDestructor Called";
    }
};
int main(){
    complex ob1;
    float real,imag;
    cout << "\nEnter the terms in the complex : ";
    cin >> real >> imag;
    complex ob2(real, imag);
    complex ob3 = ob1;
    return 0;
}