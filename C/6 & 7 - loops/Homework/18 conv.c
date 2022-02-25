#include <stdio.h>
#include <math.h>
int main(){
    int n,s=0,c=0;
    printf("Enter a number : ");
    scanf("%d",&n);
    while(n!=0){
        int r=n%2;
        s=s+r*pow(10,c);
        c++;
        n/=2;
    }
    printf("Binary form : %d \n",s);
    return 0;
}
