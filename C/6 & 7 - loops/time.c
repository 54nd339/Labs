#define pi 3.14
#define g 9.8
#define t(a) 2*pi*sqrt((a/g))
#include <stdio.h>
#include <math.h>
int main(){
    int l=10,i;
    printf("length \t Time period \n");
    for(i=1;i<=5;i++){
        printf("%d \t %f \n",l, t(l));
        l+=10;
    }
    return 0;
}
