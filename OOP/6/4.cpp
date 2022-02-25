#include <iostream>
using namespace std;
class test{
    string s;
    public:
    test(){
        s="Default";
        cout<<s+" constructor called\n";
    }
    test(int n){
        s="Parametrized";
        cout<<s+" constructor called\n";
    }
    test(test &t){
        cout<<t.s+" Copied\n";
        s="Copy";
    }
    ~test(){
        cout<<"\n"+s+" deallocated";
    }
};
int main(){
    test t1;
    test t2(1);
    test t3=t1;
    return 0;
}