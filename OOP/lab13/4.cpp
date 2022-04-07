#include <iostream>
#include <stdexcept>
using namespace std;
  
int main(){
    float num, den, res;
    cout << "Enter a numerator and denominator : ";
    cin >> num >> den;
    try {
        if (den == 0)
            throw 0;
        else {
            res = (num / den);
            cout << "Result : " << res << endl;
        }
    }
    catch (int k) {
        cout << "Division by 0" << endl;
    } 
}