/*WAP to store detail of n employees and display the detail
calculate DA=80% of Basic, HRA=10% of Basic, Gross=Basic+DA+HRA*/
#include <iostream>
using namespace std;
class employee{
    public:
    string name, id;
    int age;
    float basic, da, hra, gross;
}*e;
static int n;
void get(){
    printf("Enter no. of employees : ");
    cin>>n;
    e=new employee[n]; 
    for(int i=0;i<n;i++){
        cout<<"\nEmployee "<<i+1<<" :\n";
        cout<<"Name : ";
        cin>>(e+i)->name;
        cout<<"ID : ";
        cin>>(e+i)->id;
        cout<<"Age : ";
        cin>>(e+i)->age;
        cout<<"Basic Pay : ";
        cin>>(e+i)->basic;
        (e+i)->da=0.8*(e+i)->basic;
        (e+i)->hra=0.1*(e+i)->basic;
        (e+i)->gross=(e+i)->basic+(e+i)->da+(e+i)->hra;
    }
}
void print(){
    printf("sl.no.\tName\tID\tAge\tBasic\tDA\tHRA\tGross\n");
    for(int i=0;i<n;i++)
        cout<<i<<"\t"<<(e+i)->name<<"\t"<<(e+i)->id<<"\t"<<(e+i)->age<<"\t"<<(e+i)->basic
            <<"\t"<<(e+i)->da<<"\t"<<(e+i)->hra<<"\t"<<(e+i)->gross<<"\n";
}
int main(){
    cout<<"\nEnter Details :\n";
    get();
    cout<<"\nEntered Details :\n";
    print(); 
    return 0;
}