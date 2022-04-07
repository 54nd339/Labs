#include<iostream>
using namespace std;
class c2;
class c1{
    int m;
    public:
    c1(){ scanf("%d",&m); }
    friend int compare(c1 *x, c2 *y);
};
class c2{
    int m;
    public:
    c2(){ scanf("%d",&m); }
    friend int compare(c1 *x, c2 *y);
};
int compare(c1 *x, c2 *y){
    return x->m == y->m ? 1 : 0;
}
int main(){
    cout << "Enter 2 nos. : ";
    c1 x; c2 y;
    cout << (compare(&x,&y) ? "Equal" : "Not Equal");
    return 0;
}