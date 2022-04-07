#include <stdio.h>
int main(){
    printf("Enter a number : ");
    int n; scanf("%d",&n);
    int m = n, sum = 0;
    while (n>0){
        int r = n%10;
        int pro = 1;
        for(int i=2; i<=r; i++)
            pro *= i;
        sum += pro; n /= 10;
    }
    if(m == sum)
        printf("%d is a Strong no.\n",m);
    else
        printf("%d is not a Strong no.\n",m);
    return 0;
}