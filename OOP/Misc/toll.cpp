#include <iostream>
using namespace std;
class TollBooth{
    unsigned int cars;
    double amount;
    public:
    TollBooth(){
        cars = 0;
        amount = 0.0;
    }
    void PayingCar(){
        cars++;
        amount += 0.5;
    }
    void nopayCar(){
        cars++;
    }
    void show(){
        cout << "Total Cars Passed : " << cars << endl;
        cout << "Total amount collected : " << amount << endl;
    }
};
int main(){
    TollBooth t;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=i; j++)
            t.PayingCar();
        t.nopayCar();
    }
    t.show();
    return 0;
}