#include <stdio.h>
int main(){
    printf("Enter the base:");
    int n; scanf("%d",&n);
    printf("Enter the exponent:");
    int x; scanf("%d",&x);
    int pro = 1;
    for(int i=1; i<=x; i++)
        pro *= n;
    printf("%d ^ %d = %d\n",n,x,pro);
    return 0;
}
