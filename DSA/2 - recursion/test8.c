#include <stdio.h>
int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
int lcm(int a, int b){
    return (a/gcd(a, b)) * b;
}
int main(){
    int x, y;
    printf("Enter 2 nos. : ");
    scanf("%d%d",&x,&y);
    printf("LCM of %d and %d is %d ", x, y, lcm(x, y));
    return 0;
}