#include<iostream>
using namespace std;
class mb;
class ma{
    int x;
    public:
    ma(int n){
        x=n;
    }
    friend void show(ma a, mb b);
    friend void swap(ma &a, mb &b);
};
class mb{
    int x;
    public:
    mb(int n){
        x=n;
    }
    friend void show(ma a, mb b);
    friend void swap(ma &a, mb &b);
};
void show(ma a, mb b){
    cout<<a.x<<" "<<b.x<<endl;
}
void swap(ma &a, mb &b){
        a.x=a.x+b.x;
        b.x=a.x-b.x;
        a.x=a.x-b.x;
    }
int main(){
    int a,b;
    cout<<"Enter 2 nos. : ";
    cin>>a>>b;
    ma x(a); mb y(b);
    cout<<"Before Swap : ";
    show(x,y);
    swap(x,y);
    cout<<"After Swap : ";
    show(x,y);
    return 0;
}