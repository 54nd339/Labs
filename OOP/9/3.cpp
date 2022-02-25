#include <iostream>
using namespace std;

class base{
    protected:
    int a;
    base(int a) { this->a = a; }
};

class derived : protected base {
    int b;
    public:
    derived(int a, int b) : base(a) { this->b = b; }
    void display() {
        cout << "a: " << a << " b: " << b << endl;
    }
};

int main(){
    int a, b;
    cout << "Enter 2 nos. : ";
    cin >> a >> b;
    derived d(a, b);
    d.display();
    return 0;
}