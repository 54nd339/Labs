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
    void operator +(){ 
        DA = 0.15 * basic;
        total = DA + basic;
    }
    void display(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Dept ID : " << dept << endl;
        cout << "Basic salary : " << basic << endl;
        cout << "Total salary : " << total << endl;
        cout << endl;
    }
    //Overload the greater than (>) operator to compare between the monthly salary between two employees
    //and display the details of the employee having higher salary.
    void operator >(employee e){
        cout << "Salary compared between " << this->name << " and " << e.name << " : " << endl;
        if(this->basic == e.basic)
            cout << "Same basic salary\n" << endl;
        else if(this->basic > e.basic)
            this->display();
        else e.display();
    }
    //Overload the equals to (==) operator to verify whether the department id of two employees are same or not.
    void operator == (employee e){
        cout << "Are department same for " << this->name << " and " << e.name << " : ";
        cout << ((this->dept == e.dept) ? "yes " : "no")<<endl;
    }
};
int main(){
    employee a,b,c;
    +a; +b; +c;
    a>b; b>c; a>c;
    a==b; b==c; a==c;
    return 0;
}