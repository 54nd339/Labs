#include <iostream>
#include <cmath>
using namespace std;
float area(float r){
    return 3.14*r*r;
}
float area(float l,float b){
    return l*b;
}
float area(float a, float b, float c){
    float s = (a+b+c)/2.0;
    float p = s*(s-a)*(s-b)*(s-c);
    return sqrt(p);
}
int main(){
    cout << "1. Area of circle." << endl;
    cout << "2. Area of rectangle." << endl;
    cout << "3. Area of triangle." << endl;
    cout << "0. Exit" << endl;
    do{
        cout << "\nEnter Your Choice : ";
        int n; cin >> n;
        if(n == 1){
            cout << "Enter the radius of circle : ";
            float r; cin >> r;
            cout << "Area : " << area(r) << endl;
        }
        else if(n == 2){
            cout << "Enter the sides of the rectangle : ";
            float l, b; cin >> l >> b;
            cout << "Area : " << area(l,b) << endl;
        }
        else if(n == 3){
            cout << "Enter the sides of the triangle : ";
            float a, b, c; cin >> a >> b >> c;
            cout << "Area : " << area(a,b,c) << endl;
        }
        else if(n == 0) break;
        else cout << "Wrong input";
    }while(true);
    return 0;
}