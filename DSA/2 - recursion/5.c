#include <stdio.h>
int main(){
    int x,i=-1,ar[10],s=0;
    printf("Enter a no. : ");
    scanf("%d",&x);
    while(x){
        ar[i+1]=x%10;
        i++;x/=10;
    }
    while(i>=0){
        s=s*10+ar[i];
        i-=2;
    }
    printf("Output : %d",s);
    return 0; 
}