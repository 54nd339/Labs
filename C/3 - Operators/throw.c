#define g 9.8
#define v(a,b) a+g*b
#define s(a,b) a*b+(g*b*b)/2
#include <stdio.h>
int main(){
    printf("Enter initail velocity : ");
    int u; scanf("%d",&u);
    int t = 1;
    loop:
        printf("time: %d, velocity: %f, distance: %f\n",t, v(u,t), s(u,t));
        t++;
    if(t <= 5) goto loop;
    return 0;
}