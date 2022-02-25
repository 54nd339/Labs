#include <stdio.h>
int main(){
    int n,m,sum=0;
    printf("Enter a number : ");
    scanf("%d",&n);
    m=n;
    while(n>0){
        int r=n%10;
        sum+=(r*r*r);
        n/=10;
    }
    if(m==sum)
        printf("%d is an Armstrong no.\n",m);
    else
        printf("%d is not an Armstrong no.\n",m);
    return 0;
}
