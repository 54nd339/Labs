#include <iostream>
#include <string>
using namespace std;
class Fraction {
    int n, d;
    public:
    Fraction(int n=0, int d=1) {
        if(d==0) {
            cout << "Division by zero" << endl;
            exit(0);
        }
        this->n = n; this->d = d;
    }
    friend Fraction add(Fraction ob1, Fraction ob2) {
        Fraction res;
        res.n = ob1.n * ob2.d + ob2.n * ob1.d;
        res.d = ob1.d * ob2.d;
        return res;
    }
    friend Fraction sub(Fraction *ob1, Fraction *ob2) {
        Fraction res;
        res.n = ob1->n * ob2->d - ob2->n * ob1->d;
        res.d = ob1->d * ob2->d;
        return res;
    }
    string print(){
        Fraction res = *this;
        if(res.d==1)
            return (to_string(res.n));
        else
            return (to_string(res.n)+"/"+to_string(res.d));
    }
};
int main(){
    Fraction f1(8,9);
    Fraction f2(7,5);
    Fraction fs = add(f1,f2);
    Fraction fd = sub(&f1,&f2);
    cout << f1.print() << " + " << f2.print() << " = " << fs.print() << endl;
    cout << f1.print() << " - " << f2.print() << " = " << fd.print() << endl;
    return 0;
}