#include <stdio.h>
int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
int lcm(int a, int b){
    return (a/gcd(a, b)) * b;
}
int main(){
    printf("Enter 2 nos. : ");
    int x, y; scanf("%d%d",&x,&y);
    printf("LCM of %d and %d is %d ", x, y, lcm(x, y));
    return 0;
}