#include <iostream>
using namespace std;
float si(float p, float n, float r=20){
	return (p*n*r)/100;
}
int main(){
	float p, n, r;
	cout<<"Enter principal amount: ";
	cin>>p;
	cout<<"Enter duration (in years): ";
	cin>>n;
	cout<<"Enter rate of interest: ";
	cin>>r;
	cout<<"Simple interest = "<<si(p, n, r)<<endl;
	cout<<"Simple interest = "<<si(p, n)<<endl;
	return 0;
}
//Sandeep 20051025