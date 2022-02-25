#include<iostream>
using namespace std;
class student{
    string name; int roll;
    float m1,m2,m3;
    public :
    float avg;
    void get(){
        cout<<"\nEnter Name : ";
        cin>>name;
        cout<<"Enter Roll : ";
        cin>>roll;
        cout<<"Enter 3 marks : ";
        cin>>m1>>m2>>m3;
        avg=(m1+m2+m3)/3;
    }
    void show(){
        cout<<name<<"\t"<<roll<<"\t"<<avg;
    }
    void assign(student s){
        name=s.name; roll=s.roll;
        avg=s.avg;
    }
}s[3];

int main(){
    for(int i=0; i<2; i++){
        cout<<"\nInput "<<i+1<<" : ";
        s[i].get();
    }
    cout<<"\nDisplay :";
    cout<<"\nNo.\tName\tRoll\tavg";
    for(int i=0; i<2; i++){
        cout<<"\n"<<i+1<<"\t";
        s[i].show();
    }
    if(s[0].avg>s[1].avg) s[2].assign(s[0]);
    else s[2].assign(s[1]);
    printf("\nCopied\t");
    s[2].show();
    return 0;
}//sandeep20051025