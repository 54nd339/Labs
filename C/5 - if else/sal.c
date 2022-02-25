#include <stdio.h>
int main(){
    float hra, da, bs, gs;
    printf("Enter Base salary : ");
    scanf("%f",&bs);
    if (bs<1500){
        hra=bs*(10.0/100.0);
        da=bs*(40.0/100.0);
    }
    else{
        hra=500;
        da=bs*(50.0/100.0);
    }
    gs=bs+hra+da;
    printf("Gross Salary: %f\n",gs);
    return 0;
}
