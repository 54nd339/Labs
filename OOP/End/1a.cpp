#include <iostream>
using namespace std;
class B;
class A{
    int x;
    public:
    A(int k =0 ) { x=k; }
    friend int compare(A fir, B sec);
};
class B{
    int x;
    public:
    B(int k =0 ) { x=k; }
    friend int compare(A fir, B sec);
};
int compare(A fir, B sec){
    return (fir.x > sec.x ? fir.x : sec.x);
}
int main() {
    A m(5); B n(6);
    cout << compare(m,n);
    return 0;
}