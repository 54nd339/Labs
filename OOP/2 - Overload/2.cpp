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
    int n;
    cout<<"1. volume of sphere."<<endl;
    cout<<"2. volume of cylinder."<<endl;
    cout<<"3. volume of cuboid."<<endl;
    cout<<"0. Exit"<<endl;
    do{
        cout<<"\nEnter Your Choice : ";
        cin>>n;
        if(n==1){
            float r;
            cout<<"Enter the radius of sphere : ";
            cin>>r;
            cout<<"volume : "<<volume(r)<<endl;
        }
        else if(n==2){
            float r,h;
            cout<<"Enter the radius of base and height of the cylinder : ";
            cin>>r>>h;
            cout<<"volume : "<<volume(r,h)<<endl;
        }
        else if(n==3){
            float l,b,h;
            cout<<"Enter the sides of the cuboid : ";
            cin>>l>>b>>h;
            cout<<"volume : "<<volume(l,b,h)<<endl;
        }
        else if(n==0){
            break;
        }
        else cout<<"Wrong input";
    }while(n);
    return 0;
}