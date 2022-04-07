#include <iostream>
using namespace std;
class member {
    int roll = 0;
    static int c;
    public:
    void set(int i){
        roll = i; c++;
    }
    void show(){
        cout << "Roll : " << roll << '\t';
        cout << "Count : " << c << '\n';
    }
};

int member::c=0;
int main(){
    member n[3];
    for(int i=0; i<3; i++)
        n[i].set(i+1);
    for(int i=0; i<3; i++)
        n[i].show();
    return 0;
}