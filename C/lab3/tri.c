#include <stdio.h>
int main(){
    printf("Enter 3 sides of the triangle : ");
    int a, b, c; scanf("%d%d%d",&a,&b,&c);
    int t = (a+b>c) && (b+c>a) && (a+c>b);
    int s = t * (a+b+c);
    printf("Do they satisfy triangle property?\n");
    printf("0 if no else sum of all sides: %d\n",s);
    return 0;
}