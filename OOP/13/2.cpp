#include <iostream>
using namespace std;

template<typename T1, typename T2>
void print(T1 a, T1 b){
    cout << a << " and " << b << endl;
};
  
int main(){
    float a; int b;
    cout << "Enter a float value : ";
    cin >> a;
    cout << "Enter a int value : ";
    cin >> b;
    print <float,int>(a, b); 
    return 0;
}