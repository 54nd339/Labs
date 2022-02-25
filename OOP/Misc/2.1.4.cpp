#include<iostream>
using namespace std;
class xyz{
    int x;
    public:
    void set(){
        cout << "Enter a number : ";
        cin >> x;
    }
    xyz& operator =(const xyz& m){
        if(this!=&m)
            this->x = m.x;
        return *this;
    }
    void show(){
        cout << x << endl;
    }
};
int main(){
    xyz a, b;
    a.set();
    b=a;
    cout<<"ouput a : ";
    a.show();
    cout<<"ouput b : ";
    b.show();
}