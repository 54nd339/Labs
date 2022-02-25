#include<iostream>
using namespace std;
class student{
    protected:
    string name;
    int roll,age;
    student(){
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter roll : ";
        cin>>roll;
        cout<<"Enter age : ";
        cin>>age;
    }
};
class test : public student{
    int sub[5];
    public:
    test(){
        cout<<"Enter marks : ";
        for(int i=0;i<5;i++){
            cin>>sub[i];
        }
    }
    void show(){
        cout<<"\nName : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Marks : ";
        for(int i=0;i<5;i++){
            cout<<" "<<sub[i];
        }
    }
};
int main(){
    test ob;
    ob.show();
    return 0;
}