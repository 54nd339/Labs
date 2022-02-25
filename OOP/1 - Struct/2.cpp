/*WAP to store details of 3 employees and print the details 
by sorting them according to the basic salary*/
#include <iostream>
using namespace std;
class employee{
    public:
    string name, id, dob;
    float basic;
}e[3],temp;
void get(){
    for(int i=0;i<3;i++){
        cout<<"\nEmployee "<<i+1<<" :\n";
        cout<<"Name : ";
        cin>>e[i].name;
        cout<<"ID : ";
        cin>>e[i].id;
        cout<<"D.O.B : ";
        cin>>e[i].dob;
        cout<<"Basic Pay : ";
        cin>>e[i].basic;
    }
}
void swap(employee *x,employee *y){
    temp=*x;
    *x=*y;
    *y=temp;
}
void sort(){
    for (int i=0;i<2;i++)
        for (int j=0;j<2-i;j++)
           if (e[j].basic>e[j+1].basic)
               swap((e+j),(e+j+1));
}
void print(){
    cout<<"sl.no.\tName\tID\tDOB\t\tBasic\n";
    for(int i=0;i<3;i++)
    cout<<i<<"\t"<<e[i].name<<"\t"<<e[i].id<<"\t"<<e[i].dob<<"\t"<<e[i].basic<<"\n";
}
int main(){
    cout<<"\nEnter details :\n";
    get();
    sort();
    cout<<"\nSorted Details : \n";
    print();
    return 0;
}
//Sandeep 20051025