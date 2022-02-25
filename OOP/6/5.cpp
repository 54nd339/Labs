#include <iostream>
using namespace std;
static int c=0;
class student{
    string name; int n;
    float *marks,avg;
    public:
    student(){
        avg=0;
        cout<<"\nStudent "<<++c<<" :\n";
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter no. of subs : ";
        cin>>n;
        marks=new float[n];
        cout<<"Enter "<<n<<" marks : ";
        for(int i=0; i<n; i++){
            cin>>marks[i];
            avg+=marks[i]/n;
        }
    }
    void display(){
        cout<<name<<"\t\t";
        for(int i=0; i<n-1; i++)
            cout<<marks[i]<<"+";
        cout<<marks[n-1]<<"\t\t"<<avg<<endl;
    }
    ~student(){
        cout<<"\n"+name+" deallocated";
    }
};
int main(){
    student *a=new student[2];
    cout<<"\nDisplay :\nName\t\tMarks\t\tAverage\n";
    a->display();
    (a+1)->display();
    delete[] a;
    return 0;
}