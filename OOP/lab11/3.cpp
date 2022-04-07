#include<iostream>
using namespace std;
class Test{
	int *ptr;
    public:
	Test (int i = 0) {
        ptr = new int(i);
    }
	void setValue (int i) {
        *ptr = i;
    }
	Test & operator = (const Test &t){
        if(this != &t)
            *ptr = *(t.ptr);
        return *this;
    }
    void get() {
        cout << *ptr << endl;
    }
};
int main(){
	Test t1(5), t2 = t1;
	t1.setValue(10);
    cout << "T1 : "; t1.get();
	cout << "T2 : "; t2.get();
	return 0;
}