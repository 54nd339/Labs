#include <stdio.h>
int main(){
    int a, b, c;
    printf("Enter 3 nos. : \n");
    scanf("%d%d%d",&a,&b,&c);
    int max = a;
    if(b > max) max = b;
    if(c > max) max = c;
    printf("max : %d",max);
    return 0;
}