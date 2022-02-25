#include <iostream>
using namespace std;
class Distance {
    int feet, inches;
    public:
    Distance() {
        cout << "Enter distances (in feet, inches) : ";
        cin >> feet >> inches;
    }
    Distance operator()(int x) {
        this->inches += x;
        this->feet += this->inches/12;
        this->inches %= 12;
        return *this;
    }
    void print() {
        cout << "Distance : " << feet << " feets " << inches << " inches"<<endl;
    }   
};

int main() {
   Distance D1;
   cout << "Enter a distance to be added (in inches): ";
    int in; cin >> in;
   D1(in); D1.print();
   return 0;
}