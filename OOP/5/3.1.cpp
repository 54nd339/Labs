#include <iostream>
using namespace std;
class marks;
class student{
    string  name; int roll;
	public:
    void get(){
        cout<<"Enter name & roll: " ;
        cin>>name>>roll;
    }
    friend void show(student x,marks y);
}stud[2];
class marks{
    float m1,m2,m3;
    public:
    void get(){
        cout<<"Enter 3 marks : ";
        cin>>m1>>m2>>m3;
    }
    friend void show(student x,marks y);
}mark[2];
void show(student x,marks y){
    float avg=(y.m1+y.m2+y.m3)/3;
    cout<<x.name<<"\t"<<x.roll<<"\t"<<avg<<endl;
}
int main(){
    for(int i=0;i<2;i++){
        printf("\nStudent %d :\n",i+1);
        stud[i].get();
        mark[i].get();
    }
    cout<<"\nDisplay : \n";
    cout<<"name\troll\tavg\n";
    for(int i=0;i<2;i++)
	    show(stud[i],mark[i]);
	return 0;
}