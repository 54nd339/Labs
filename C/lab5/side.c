#include <stdio.h>
int main(){
    printf("Enter 3 sides of the triangle : \n");
    int a, b, c; scanf("%d%d%d",&a,&b,&c);
    if ((a+b>c) && (b+c>a)&&(a+c>b))
        printf("These are sides of the triangle\n");
    else
        printf("These are not sides of the triangle\n");
    return 0;
}