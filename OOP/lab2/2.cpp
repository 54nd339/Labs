#include <iostream>
#include <cmath>
using namespace std;
float volume(float r){
    return 3.14*r*r*r;
}
float volume(float r,float h){
    return 3.14*r*r*h;
}
float volume(float l, float b, float h){
    return l*b*h;
}
int main(){
    cout << "1. volume of sphere." << endl;
    cout << "2. volume of cylinder." << endl;
    cout << "3. volume of cuboid." << endl;
    cout << "0. Exit" << endl;
    do{
        cout << "\nEnter Your Choice : ";
        int n; cin >> n;
        if(n == 1){
            cout << "Enter the radius of sphere : ";
            float r; cin >> r;
            cout << "volume : " << volume(r) << endl;
        }
        else if(n == 2){
            cout << "Enter the radius of base and height of the cylinder : ";
            float r, h; cin >> r >> h;
            cout << "volume : " << volume(r,h) << endl;
        }
        else if(n == 3){
            cout << "Enter the sides of the cuboid : ";
            float l, b, h;cin >> l >> b >> h;
            cout << "volume : " << volume(l,b,h) << endl;
        }
        else if(n==0) break;
        else cout << "Wrong input";
    }while(true);
    return 0;
}