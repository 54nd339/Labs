#define pi 3.14
#define g 9.8
#define t(a) 2*pi*sqrt((a/g))
#include <stdio.h>
#include <math.h>
int main(){
    int l = 10;
    printf("length \t Time period \n");
    printf("%d \t %f \n",l, t(l));
    l += 10;
    printf("%d \t %f \n",l, t(l));
    l += 10;
    printf("%d \t %f \n",l, t(l));
    l += 10;
    printf("%d \t %f \n",l, t(l));
    l += 10;
    printf("%d \t %f \n",l, t(l));
    return 0;
}