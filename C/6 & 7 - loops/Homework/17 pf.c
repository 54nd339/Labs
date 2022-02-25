#include <stdio.h>
int main()
{
    int i,n,m;
    printf("Enter a number:");
    scanf("%d",&n);
    m=n;
    printf("Prime Factors of %d are:\n",n);
    for(i=2;i<=m;i++){
        while(m%i==0){
            m/=i;
            printf("%d\n",i);
        }
    }
    return 0;
}
