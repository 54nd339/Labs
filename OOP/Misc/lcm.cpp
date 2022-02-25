#include <iostream>
using namespace std;
class b;
class a{
    int x;
    public:
    a(int val=0) { x = val; }
    friend int lcm(a x, b y);
};
class b{
    int y;
    public:
    b(int val=0) { y = val; }
    friend int lcm(a x, b y);
};
int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(a A, b B){
    return (A.x / gcd(A.x, B.y)) * B.y;
}
int main(){
    a A(2); b B(3);
    cout<< "lcm :" << lcm(A, B) <<endl;
    A=12;
    cout<< "lcm :" << lcm(A, B) <<endl;
    return 0;
}