#include <iostream>
#include <string>
#include <algorithm>
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
    Complex operator -(Complex &obj) {
        return Complex(this->r - obj.r, this->i - obj.i);
    }
    Complex operator *(Complex &obj) {
        Complex t;
        t.r = this->r*obj.r - this->i*obj.i;
        t.i = this->r*obj.i + this->i*obj.r;
        return t;
    }
    string print(){
        if(r==0 && i==0) return "0";
        else if(i==0)
            return (to_string(r));
        else if(r==0)
            return (to_string(i)+"i");
        else if(i<0)
            return (to_string(r)+" "+to_string(i)+"i");
        else
            return (to_string(r)+"+"+to_string(i)+"i");
    }
};
class Fraction {
    int n, d;
    Fraction reduce(Fraction &obj){
        int gcd = __gcd(obj.n, obj.d);
        return Fraction(obj.n/gcd, obj.d/gcd);
    }
    public:
    Fraction(int n=0, int d=1) {
        this->n = n; this->d = d;
    }
    Fraction operator +(Fraction &obj) {
        Fraction res;
        res.n = this->n * obj.d - obj.n * this->d;
        res.d = this->d * obj.d;
        return reduce(res);
    }
    Fraction operator -(Fraction &obj) {
        Fraction res;
        res.n = this->n * obj.d + obj.n * this->d;
        res.d = this->d * obj.d;
        return reduce(res);
    }
    Fraction operator *(Fraction &obj) {
        Fraction res;
        res.n = this->n * obj.n;
        res.d = this->d * obj.d;
        return reduce(res);
    }
    operator float(){
        return float(n)/float(d);
    }
    string print(){
        Fraction res = reduce(*this);
        if(res.d==1)
            return (to_string(res.n));
        else
            return (to_string(res.n)+"/"+to_string(res.d));
    }
};
int main(){
    Complex c1(3,-5);
    Complex c2(-4,6);
    Complex cs = c1 + c2;
    Complex cd = c1 - c2;
    Complex cp = c1 * c2;
    cout << c1.print() << " + " << c2.print() << " = " << cs.print() << endl;
    cout << c1.print() << " - " << c2.print() << " = " << cd.print() << endl;
    cout << c1.print() << " * " << c2.print() << " = " << cp.print() << endl;

    Fraction f1(8,9);
    Fraction f2(7,5);
    Fraction fs = f1 + f2;
    Fraction fd = f1 - f2;
    Fraction fp = f1 * f2;
    cout << f1.print() << " + " << f2.print() << " = " << fs.print() << endl;
    cout << f1.print() << " - " << f2.print() << " = " << fd.print() << endl;
    cout << f1.print() << " * " << f2.print() << " = " << fp.print() << endl;
    cout << float(f1) << " + " << float(f2) << " = " << float(fs) << endl;
    cout << float(f1) << " - " << float(f2) << " = " << float(fd) << endl;
    cout << float(f1) << " * " << float(f2) << " = " << float(fp) << endl;
    return 0;
}