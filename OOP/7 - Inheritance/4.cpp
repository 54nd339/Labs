#include<iostream>
using namespace std;
class company{
    protected:
    string name;
    int year;
    company(){
        name=""; year=0;
    }
};
class employee : public company{
    string ename, desig;
    int age,ecode;
    public:
    employee(){
        cout<<"\nEnter Employee Details : "<<endl;
        cout<<"Enter name : ";
        cin>>ename;
        cout<<"Enter designation : ";
        cin>>desig;
        cout<<"Enter employee code : ";
        cin>>ecode;
        cout<<"Enter age : ";
        cin>>age;
    }
    void show(){
        cout<<"\nEmployee Details : "<<endl;
        cout<<"Name of employee : "<<ename<<endl;
        cout<<"Designation : "<<desig<<endl;
        cout<<"Employee Code : "<<ecode<<endl;
        cout<<"Age : "<<age<<endl;
    }
};
class department : public company{
    string dname;
    int eno,dcode;
    public:
    department(){
        cout<<"\nEnter Company Details : "<<endl;
        cout<<"Enter Company name : ";
        cin>>name;
        cout<<"Enter year of establishment : ";
        cin>>year;
        cout<<"\nEnter Department Details : "<<endl;
        cout<<"Enter department name : ";
        cin>>dname;
        cout<<"Enter department code : ";
        cin>>dcode;
        cout<<"Enter no. of employees : ";
        cin>>eno;
    }
    void show(){
        cout<<"\nCompany Details : "<<endl;
        cout<<"Name of company : "<<name<<endl;
        cout<<"Year of establishment : "<<year<<endl;
        cout<<"\nDepartment Details : "<<endl;
        cout<<"Department Name : "<<dname<<endl;
        cout<<"Department Code : "<<dcode<<endl;
        cout<<"No. of employees : "<<eno<<endl;
    }
};
int main(){
    department d;
    employee e;
    d.show();
    e.show();
    return 0;
}