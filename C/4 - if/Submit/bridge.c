#include <stdio.h>
int main(){
    float p,q,r,s;
    printf("Enter 4 resistances of the wheatstone bridge : \n");
    scanf("%f%f%f%f",&p,&q,&r,&s);
    if((p*s)==(r*q)){
        printf("The wheatstone bridge is balanced\n");
        return 0;
    }
    s = (q*r)/p;
    printf("The wheatstone bridge can be balanced with s = %f\n",s);
    return 0;
}