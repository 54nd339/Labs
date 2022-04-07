#include<iostream>
using namespace std;
class student{
    protected:
    string name;
    int roll, age;
    student(){
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter roll : ";
        cin >> roll;
        cout << "Enter age : ";
        cin >> age;
    }
};
class test : public student{
    protected:
    int sub[5];
    test(){
        cout << "Enter marks : ";
        for(int i=0; i<5; i++){
            cin >> sub[i];
        }
    }
};
class result : protected test{
    int total; float percent;
    public:
    result(){
        total = 0;
        for(int i=0; i<5; i++){
            total += sub[i];
        }
        percent = total/5.0;
    }
    void show(){
        cout << "\nName : " << name << endl;
        cout << "Roll : " << roll << endl;
        cout << "Age : " << age << endl;
        cout << "Marks : ";
        for(int i=0; i<5; i++){
            cout << " " << sub[i];
        }
        cout << "\nTotal : " << total << endl;
        cout << "Percent : " << percent << endl;
    }
};
int main(){
    result ob;
    ob.show();
    return 0;
}