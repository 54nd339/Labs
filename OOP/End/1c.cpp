#include <iostream>
using namespace std;
class A{
    static int x;
    public:
    A(){ x++; }
    static void print(){
        cout << x << endl;
    }
};
int A::x=0; 
int main() {
    A num[5];
    A::print();
    return 0;
}