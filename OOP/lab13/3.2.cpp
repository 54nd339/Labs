#include <iostream>
using namespace std;

template<class T1, class T2>
class Test{
    T1 a; T2 b;
    public:
    Test(){
        cout << "Enter a float value : ";
        cin >> a;
        cout << "Enter a int value : ";
        cin >> b;
    }
    void show(){
        cout << a << " and " << b << endl;
    }
};
  
int main(){
    Test <float, int> test;
    test.show(); 
    return 0;
}