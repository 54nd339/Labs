#include <stdio.h>
int main(){
    printf("Enter 3 sides of the triangle : ");
    int a, b, c; scanf("%d%d%d",&a,&b,&c);
    int t = ((a+b>c) + (b+c>a) + (a+c>b))/3;
    printf("Do they satisfy triangle property?\n");
    printf("0 if no, 1 if yes: %d\n",t);
    return 0;
}