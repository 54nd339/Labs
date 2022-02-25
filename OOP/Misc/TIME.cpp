#include <iostream>
using namespace std;
class Time{
    int hh, mm, ss;
    public:
    Time(){
        hh=mm=ss=0;
    }
    void accept(){
        cin>>hh>>mm>>ss;
    }
    friend Time add(Time x, Time y){
        Time res;
        res.ss=x.ss+y.ss;
        res.mm=x.mm+y.mm+(res.ss/60);
        res.hh=x.hh+y.hh+(res.mm/60);
        res.mm%=60;
        res.ss%=60;
        return res;
    }
    void display(){
        cout<<hh<<":"<<mm<<":"<<ss;
    }
};
int main(){
    Time ob1,ob2;
    ob1.accept();
    ob2.accept();
    Time res=add(ob1,ob2);
    res.display();
    return 0;
}