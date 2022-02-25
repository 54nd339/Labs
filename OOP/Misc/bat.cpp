#include <iostream>
using namespace std;
class Player{
    string name;
    int run, inn, out;
    float avg;
    public:
    Player(string name="", int run=0, int inn=0, int out=0){
        cin>>this->name>>this->run>>this->inn>>this->out;
        avg=(float)this->run/this->inn;
    }
    void print(){
        cout<<"\nName : "<<name<<endl;
        cout<<"Runs scored : "<<run<<endl;
        cout<<"Innings Played : "<< inn<<endl;
        cout<<"Times not out : "<< out<<endl;
        cout<<"Batting Average : "<< avg<<endl;
    }
};
int main(){
    int n;
    cout<<"Enter no. of players : ";
    cin>>n;
    Player obj[n];
    for(int i=0; i<n; i++)
        obj[i].print();
    return 0;
}