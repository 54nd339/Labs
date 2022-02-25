#include <iostream>
#include <cstring>
using namespace std;
class str{
    string s; int len;
    public:
    str(){
        cout<<"Enter a string : ";
        cin>>s; len=s.length();
    }
    str(string in){
        s=in; len=in.length();
    }
    void join(str ob){
        s+=ob.s; len+=ob.len;
        cout<<"\nString : "<<s<<"\nlength : "<<len<<"\n\n";
    }
    ~str(){
        cout<<"Destructor Called"<<endl;
    }
};
int main(){
    str ob1; string in;
    cout<<"Enter a string : ";
    cin>>in;
    str ob2(in);
    ob1.join(ob2);
    return 0;
}