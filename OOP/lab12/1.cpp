#include <iostream>
using namespace std;
class dis{
    int feet, inches;
    public:
    void get(){
        cout<<"Enter Distance (feet, inches) : ";
        cin >> feet >> inches; 
    }
    dis operator +(dis &d){
        dis d3;
        d3.inches = this->inches + d.inches;
        d3.feet = this->feet + d.feet + d3.inches/12;
        d3.inches %= 12; return d3;
    }
    dis operator +(int d){
        dis d2;
        d2.inches = this->inches + d;
        d2.feet = this->feet + d2.inches/12;
        d2.inches %= 12; return d2;
    }
    void print(){
        cout << feet << " feets, " << inches << " inches" <<endl;
    }
};
int main(){
    dis d1, d2, d3;
    d1.get(); d2.get();
    d3 = d1 + d2;
    d3.print();
    printf("\nEnter inches to be added to d1 : ");
    int in; cin>>in;
    d2 = d1 + in;
    d2.print();
}