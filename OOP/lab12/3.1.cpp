#include <iostream>
using namespace std;
class Complex {
    int r, i;
    public:
    Complex(int r=0, int i=0) {
        this->r = r; this->i = i;
    }
    Complex operator +(Complex &obj) {
        return Complex(this->r + obj.r, this->i + obj.i);
    }
    string print(){
        return (to_string(r)+" + "+to_string(i)+"i");
    }
};
int main(){
    int r1, i1, r2, i2;
    cout << "Enter real and imaginary of complex 1 : ";
    cin >> r1 >> i1;
    Complex c1(r1, i1);
    cout << "Enter real and imaginary of complex 2 : ";
    cin >> r2 >> i2;
    Complex c2(r2, i2);
    Complex cs = c1 + c2;
    cout << "Sum : " << cs.print() << endl;
    return 0;
}