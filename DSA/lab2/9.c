#include <stdio.h>
int sum(int n){
    if(n == 0) return 0;
    return (n%2) ? 0+sum(n/10) : (n%10)+sum(n/10);
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf("sum of even digits : %d",sum(x));
    return 0; 
}