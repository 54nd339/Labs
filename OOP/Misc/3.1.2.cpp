#include <iostream>
using namespace std;
template <class T>
void display(T t1){
	cout << "Displaying Template: " << t1 << "\n";
}
void display(int t1){
	cout << "Explicitly display: " << t1 << "\n";
}

int main(){
	int n; char ch; double d;
	cout << "Enter an int, char, double : ";
	cin >> n >> ch >> d;
    display(n);
	display(ch);
	display(d);

	return 0;
}
