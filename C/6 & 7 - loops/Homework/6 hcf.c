#include <stdio.h>
int main(){
    int m,i,n,pro,hcf=0;
    printf("Enter 2 nos. : ");
    scanf("%d %d",&m,&n);
    pro=m*n;
    for(i=1;i<=pro;i++)
    {
        if(m%i==0 && n%i==0)
        hcf=i;
    }
    printf("HCF of %d and %d is %d\n",m,n,hcf);
    return 0;
}
