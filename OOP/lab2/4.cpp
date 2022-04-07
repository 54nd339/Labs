#include <iostream>
using namespace std;
float si(float p, float n, float r=20){
	return (p*n*r)/100;
}
int main(){
	cout << "Enter principal amount: ";
	float p; cin >> p;
	cout << "Enter duration (in years): ";
	float n; cin >> n;
	cout << "Enter rate of interest: ";
	float r; cin >> r;
	cout << "Simple interest = " << si(p, n, r) << endl;
	cout << "Simple interest = " << si(p, n) << endl;
	return 0;
}