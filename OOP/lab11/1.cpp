#include <iostream>
using namespace std;
class employee {
    string name, dept;
    int age; float salary;
    public:
    employee(){
        cout << endl << "Enter Name : ";
        cin >> name;
        cout << "Enter Age : ";
        cin >> age;
        cout << "Enter Department : ";
        cin >> dept;
        cout << "Enter Salary : ";
        cin >> salary;
    }
    void *operator new(size_t size){
		cout << "Overloading new operator with size: " << size << endl;
		void *p = ::operator new(size);
        return p;
	}
    void show(){
		cout << endl << "Name : " << name << endl;
		cout << "Age : " << age << endl;
        cout << "Department : " << dept << endl;
        cout << "Salary : " << salary << endl;
	}
};

int main(){
	employee *p = new employee[2];
	p[0].show(); p[1].show();
    return 0;
}