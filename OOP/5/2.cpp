#include<iostream>
using namespace std;
class IF;
class MC{
    float meters,centimeters;
    public:
    MC(float m, float c){
 	    meters = m;
 	    centimeters  = c;
    }
    friend void compare(MC x,IF y);
};
class IF{
    float inch, feet;
    public:
    IF(float f, float i){
        feet = f;
        inch = i;
    }
    friend void compare(MC x,IF y);
};
void compare(MC a,IF b){
    float mc=a.meters*100+a.centimeters;
    float fi=b.feet*30.5+b.inch*2.5;
    cout<<"Greater Distance : ";
	if(mc>fi)
		cout<<a.meters<<" m "<<a.centimeters<<" cm"<<endl;
	else
		cout<<b.feet<<" ft. "<<b.inch<<" in."<<endl;
}
int main(){
    float a,b;
    cout<<"Enter distance in m and cm : ";
    cin>>a>>b;
    MC x(a,b);
    cout<<"Enter distance in ft. and in. : ";
    cin>>a>>b;
    IF y(a,b);
    compare(x,y);
    return 0;
}