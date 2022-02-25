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
    float s=(a+b+c)/2.0;
    float p=s*(s-a)*(s-b)*(s-c);
    return sqrt(p);
}
int main(){
    int n;
    cout<<"1. Area of circle."<<endl;
    cout<<"2. Area of rectangle."<<endl;
    cout<<"3. Area of triangle."<<endl;
    cout<<"0. Exit"<<endl;
    do{
        cout<<"\nEnter Your Choice : ";
        cin>>n;
        if(n==1){
            float r;
            cout<<"Enter the radius of circle : ";
            cin>>r;
            cout<<"Area : "<<area(r)<<endl;
        }
        else if(n==2){
            float l,b;
            cout<<"Enter the sides of the rectangle : ";
            cin>>l>>b;
            cout<<"Area : "<<area(l,b)<<endl;
        }
        else if(n==3){
            float a,b,c;
            cout<<"Enter the sides of the triangle : ";
            cin>>a>>b>>c;
            cout<<"Area : "<<area(a,b,c)<<endl;
        }
        else if(n==0){
            break;
        }
        else cout<<"Wrong input";
    }while(n);
    return 0;
}
//Sandeep 20051025