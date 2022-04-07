#include <iostream>
using namespace std;
class student{
    string name; float marks;
    static float avg;
    static int c;
    public:
    student(){
        cout << "\nStudent " << ++c << " :\n";
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter marks : ";
        cin >> marks;
        avg += marks/2;
    }
    void display(){
        cout << name << "\t" << marks << endl;
    }
    ~student(){
        if(--c) printf("\nAverage : %.2f",avg);
        else cout << "\nMemory deallocated";
    }
};
float student::avg = 0;
int  student::c = 0;
int main(){
    student *a = new student[2];
    cout << "\nDisplay :\nName\tMarks\n";
    a->display(); (a+1)->display();
    delete[] a;
    return 0;
}