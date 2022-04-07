#include <iostream>
using namespace std;
class department{
    protected:
    string dname, did;
};
class accounts;
class employee : protected department{
    string ename, eid;
    int age;
    public :
    employee(){
        cout << "Enter department name and id : ";
        cin >> dname >> did;
        cout << "Enter employee name, id and age : ";
        cin >> ename >> eid >> age;
    }
    friend void show(employee e, accounts a);
};
class accounts : protected department{
    float basic;
    public:
    accounts(){
        cout << "Enter Basic : ";
        cin >> basic;
    }
    friend void show(employee e, accounts a);
};
void show(employee e, accounts a){
    cout << "\nDepartment Name : " << e.dname << endl;
    cout << "Department ID : " << e.did << endl;
    cout << "Employee Name : " << e.ename << endl;
    cout << "Employee ID : " << e.eid << endl;
    cout << "Employee Age : " << e.age << endl;
    cout << "Basic : " << a.basic << endl;
    cout << "DA : " << 0.15*a.basic << endl;
    cout << "HRA : " << 0.1*a.basic << endl;
    cout << "Total : " << 1.25*a.basic << endl;
}
int main(){
    employee e;
    accounts a;
    show(e, a);
    return 0;
}