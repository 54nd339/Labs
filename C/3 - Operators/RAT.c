#define s(n) (n*n)
#include <stdio.h>
int main(){
    int a,b,c,t;
    printf("Enter 3 sides of the triangle :\n");
    scanf("%d%d%d",&a,&b,&c);
    t = (s(a)==s(b)+s(c)) || (s(c)==s(a)+s(b)) || (s(b)==s(c)+s(a));
    printf("Are they side of right angled triangle?:\n");
    printf("Display : 1 if yes, 0 if no : %d \n",t);
    return 0;
}