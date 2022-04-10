#include <stdio.h>
int check(int a, int b, int n){
    if(a <= n)
        return (n==a)? 1 : check(b, a+b, n);
    return 0;
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf(check(0,1,x) ? "Present" : "Absent");
    return 0; 
}