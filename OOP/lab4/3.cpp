#include <iostream>
using namespace std;
class employee{
    static string dept;
    string name, job_id;
    int age;
    public:
    void get(){
        cout << "\nName : ";
        cin >> name;
        cout << "Job ID : ";
        cin >> job_id;
        cout << "Age : ";
        cin >> age;
    }
    void show(){
        cout << name << "\t" << job_id << "\t" << dept << "\t" << age;
    }
}e[3];

string employee::dept="CSE";
int main(){
    for(int i=0; i<3; i++){
        cout << "\nInput " << i+1 << " : ";
        e[i].get();
    }
    cout << "\nDisplay :";
    cout << "\nNo.\tName\tID\tDept\tAge";
    for(int i=0; i<3; i++){
        cout << "\n" << i+1 << "\t";
        e[i].show();
    }
    return 0;
}