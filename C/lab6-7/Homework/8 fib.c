#include <stdio.h>
int main(){
    int n, i, a=0, b=1, c;
    printf("Enter the no. of terms : ");
    scanf("%d",&n);
    printf("Fibonacci Series :\n");
    for(i=1; i<=n; i++) {
        printf("%d\n",a);
        c=b; b+=a; a=c;
    }
    return 0;
}