#include <iostream>
using namespace std;
class unary{
    int i;
    public:
    unary(int i = 0){
        this->i = i;
    }
    unary operator -- () {
        unary temp; 
        temp.i = --i;
        return temp;
    }
    unary operator ++ (int) {
        unary temp; 
        temp.i = i++;
        return temp;
    }
    void print(){
        cout<<"i = "<<i<<endl;
    }
};

int main(){
    cout << "enter the value : ";
    int i; cin >> i;
    unary n = i, res;
    n.print();
    res = --n; res.print();
    n.print();
    res = n++; res.print();
    n.print();
    return 0;
}