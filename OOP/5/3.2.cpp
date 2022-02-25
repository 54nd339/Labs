#include <iostream>
using namespace std;
class marks;
class student{
    string  name; int roll;
	public:
    void get(){
        cout<<"Enter name & roll : " ;
        cin>>name>>roll;
    }
    void show(marks y);
}stud[2];
class marks{
    float m1,m2,m3;
    public:
    void get(){
        cout<<"Enter 3 marks : ";
        cin>>m1>>m2>>m3;
    }
    friend void student::show(marks y);
}mark[2];
void student::show(marks y){
    float avg=(y.m1+y.m2+y.m3)/3;
    cout<<name<<"\t"<<roll<<"\t"<<avg<<endl;
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
	    stud[i].show(mark[i]);
	return 0;
}