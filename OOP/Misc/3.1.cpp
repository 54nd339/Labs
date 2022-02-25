#include <iostream>
using namespace std;

template<class T>
class Test{
    T a;
    public:
    Test(){
        cin >> a;
    }
    template<class f>
    void show(f b){
        cout << a << " * "<< b << " is " << a*b << endl;
    }
    void show(char ch){
        cout << "Cannot multiply char" << endl;
    }
};
  
int main(){
    int b;
    cout << "Enter 2 int value : ";
    Test <int> test1; cin >> b;
    test1.show(b);

    float x;
    cout << "Enter 2 float value : ";
    Test <float> test2; cin >> x;
    test2.show(x); 

    char y;
    cout << "Enter 2 char value : ";
    Test <char> test3; cin >> y;
    test3.show(y); 
    return 0;
}