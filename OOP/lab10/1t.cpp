#include<iostream>
using namespace std;
class employee{
    string name, dept; int age;
    float basic, DA, total;
    public:
    employee(){
        cout << "enter name : ";
        cin >> name;
        cout << "enter age : ";
        cin >> age;
        cout << "enter dept id : ";
        cin >> dept;
        cout << "enter basic : ";
        cin >> basic;
        cout << endl;
    }
    //Overload the binary  plus (+) operator to add DA as 15% of basic salary.
    friend void operator +(employee &e){
        e.DA = 0.15 * e.basic;
        e.total = e.DA + e.basic;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Dept ID : "<<dept<<endl;
        cout<<"Basic salary : " <<basic<<endl;
        cout<<"Total salary : "<<total<<endl;
        cout << endl;
    }
    //Overload the greater than (>) operator to compare between the monthly salary between two employees
    //and display the details of the employee having higher salary.
    friend void operator >(employee e1, employee e2){
        cout<<"Salary compared between "<<e1.name<<" and "<<e2.name<<" : "<<endl;
        if(e1.basic == e2.basic)
            cout << "Same basic salary\n" << endl;
        else if(e1.basic>e2.basic)
            e1.display();
        else e2.display();
    }
    //Overload the equals to (==) operator to verify whether the department id of two employees are same or not.
    friend void operator == (employee e1, employee e2){
        cout<<"Are department same for "<<e1.name<<" and "<<e2.name<<" : ";
        cout << ((e1.dept == e2.dept) ? "yes " : "no")<<endl;
    }
};
int main(){
    employee a,b,c;
    +a; +b; +c;
    a>b; b>c; a>c;
    a==b; b==c; a==c;
    return 0;
}