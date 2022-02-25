#include<iostream>
using namespace std;
class student{
	string name;
	int age;
    public:
	student(){
		cout << "Enter name and age : ";
        cin >> name >> age;
	}
    void *operator new(size_t size){
		cout<< "Overloading new operator with size: " << size << endl;
		void *p = ::operator new(size);
        return p;
	}
	void operator delete(void * p){
		cout<< "Overloading delete operator " << endl;
		free(p);
	}
    void show(){
		cout<< "Name:" << name << endl;
		cout<< "Age:" << age << endl;
	}
};

int main(){
	student *p = new student();
	p->show();
	delete p;
}
