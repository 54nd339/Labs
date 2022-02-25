//20051025 Sandeep
#include <iostream>
using namespace std;

template<typename T1>
void swap(T1 *a, T1 *b){
    T1 temp = *a;
    *a = *b; *b = temp;
};
  
int main(){
    float a, b;
    cout << "Enter 2 float value : ";
    cin >> a >> b;
    swap <float>(&a, &b);
    cout << a << " " << b << endl;

    int x, y;
    cout << "Enter 2 int value : ";
    cin >> x >> y;
    swap <int>(&x, &y);
    cout << x << " " << y << endl; 
    return 0;
}