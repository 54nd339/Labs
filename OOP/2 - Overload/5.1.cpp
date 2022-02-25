#include <iostream>
#include <cstring>
using namespace std;
void print(){
    for(int i=0;i<80;i++)
        cout<<"* ";
}
void print(char c){
    for(int i=0;i<80;i++)
        cout<<c<<' ';
}
void print(char c,int n){
    for(int i=0;i<n;i++)
        cout<<c<<' ';
}
int main(){
    string s,t;int x;
    for(int i=0;i<3;i++){
        cout<<"\nEnter a charecter : ";
        getline(cin,s);
        if(s.empty()) print('*');
        else{
            cout<<"Enter a number : ";
            getline(cin,t);
            if(t.empty()) print(s[0]);
            else{
                x=stoi(t);
                print(s[0],x);
            }
        }
        cout<<"\n";
    }
    return 0;
}
//Sandeep 20051025