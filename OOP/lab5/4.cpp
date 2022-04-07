#include <iostream>
using namespace std;
class test {
    static int count;
    public:
	test(){
	    count++;
	}
    static void show(){
		cout << "count : " << count << endl;
	}
};
int test::count = 0;
int main(){
    cout << "Enter no. of objs : ";
    int n; cin >> n;
    test ar[n];
	ar[n-1].show();
	return 0;
}