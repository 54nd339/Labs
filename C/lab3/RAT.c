#define s(n) (n*n)
#include <stdio.h>
int main(){
    printf("Enter 3 sides of the triangle :\n");
    int a, b, c; scanf("%d%d%d",&a,&b,&c);
    int t = (s(a)==s(b)+s(c)) || (s(c)==s(a)+s(b)) || (s(b)==s(c)+s(a));
    printf("Are they side of right angled triangle?:\n");
    printf("Display : 1 if yes, 0 if no : %d \n",t);
    return 0;
}