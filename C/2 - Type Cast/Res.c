#define V 300
#include <stdio.h>
int main(){
    int r1,r2,r3;
    printf("Enter 3 resistance :\n");
    scanf("%d%d%d",&r1,&r2,&r3);
    float rs = r1+r2+r3;
    printf("Equivalent resistance in series is %f\n",rs);
    float temp = (float)1/r1+(float)1/r2+(float)1/r3;
    float rp = 1/temp;
    printf("Equivalent resistance in parellel is %f\n",rp);
    printf("Equivalent resistance in parellel is %f\n",(1/temp));
    printf("Current in series circuit is %f\n",(V/rs));
    printf("Current in parellel circuit is %f\n",(V/rp));
    return 0;
}