#include <iostream>
using namespace std;
class Student{
    static float avg;
    public:
    string name;
    int roll;
    float total;
    void average(){
        avg += total;
    }
    static void print(int n){
        cout << "\nAverage : " << avg/n << endl;
    }
};
float Student::avg = 0; 
int main() {
    cout << "Enter No. of students : ";
    int n; cin >> n;
    Student s[n];
    cout<<"Enter Details : \n";
    for(int i=0; i<n; i++){
        cout << "\nStudent "<<i+1<<" : \n";
        cout << "Enter Name : ";
        cin >> s[i].name;
        cout << "Enter Roll : ";
        cin >> s[i].roll;
        cout << "Enter Total : ";
        cin >> s[i].total;
        s[i].average();
    }
    Student::print(n);
    return 0;
}