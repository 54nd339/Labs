#include <stdio.h>
int common=0;
int lcm(int a, int b){
    common+=b;
    return (common%a==0)? common: lcm(a,b);
}
int main(){
    int x, y, res;
    printf("Enter 2 nos. : ");
    scanf("%d%d",&x,&y);
    res=(x<y)?lcm(x,y):lcm(y,x); 
    printf("LCM of %d and %d is %d ", x, y, res);
    return 0;
}