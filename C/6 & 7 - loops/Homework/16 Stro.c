#include <stdio.h>
int main(){
    int n,i,m,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    m=n;
    while(n>0){
        int r=n%10;
        int pro=1;
        for(i=2;i<=r;i++)
            pro*=i;
        sum+=pro;
        n/=10;
    }
    if(m==sum)
        printf("%d is a Strong no.\n",m);
    else
        printf("%d is not a Strong no.\n",m);
    return 0;
}
