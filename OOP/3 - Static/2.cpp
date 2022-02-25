#include <iostream>
using namespace  std;
class power{
    public:
    inline int square(int n){
        return n*n;
    }
    inline int cube(int n){
        return n*n*n;
    }
};
int main(){
    int n,r;
    power p;
    cout<<"\nEnter the Number : " ;
    cin>>n;
    r=p.square(n);
    cout<<"Square of "<<n<<" = "<<r<<"\n";
    r=p.cube(n);
    cout<<"Cube of "<<n<<" = "<<r<<"\n";
    return 0;
} //Sandeep 20051025