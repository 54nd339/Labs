#include <iostream>
using namespace std;
class time{
    int hh,mm;
    public:
    void display(){
        hh+=mm/60; mm%=60; hh%=24;
        cout<<hh<<" : "<<mm<<endl;
    }
    time(){
        cout<<"\nDefault Constructor called";
        cout<<"\nEnter hh : mm : ";
        cin>>hh>>mm; this->display();
    }
    time(int h, int m){
        cout<<"Parameterized Constructor called\n";
        hh=h; mm=m; this->display();
    }
    time(time &t){
        cout<<"\nCopy Constructor called\n";
        hh=t.hh; mm=t.mm; this->display();
    }
    ~time(){
        cout<<"\nDestructor Called";
    }
};
int main(){
    time ob1;
    int h,m;
    cout<<"\nEnter hh : mm : ";
    cin>>h>>m;
    time ob2(h,m);
    time ob3 = ob1;
    return 0;
}