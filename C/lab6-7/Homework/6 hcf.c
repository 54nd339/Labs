#include <stdio.h>
int main(){
    printf("Enter 2 nos. : ");
    int m, n; scanf("%d %d",&m,&n);
    int pro = m*n, hcf = 0;
    for(int i=1; i<=pro; i++) {
        if(m%i==0 && n%i==0)
        hcf = i;
    }
    printf("HCF of %d and %d is %d\n",m,n,hcf);
    return 0;
}