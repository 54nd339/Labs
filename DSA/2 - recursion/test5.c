#include <stdio.h>
#include <math.h>
int main(){
    int x,c,s=0,i=0;
    printf("Enter a no. : ");
    scanf("%d",&x);
    c=(int)log10(x);
    while(c>=0){
        if(c%2==0){
            s+=(x%10)*pow(10,i);
            i++;
        }
        c--;x/=10;
    }
    printf("Output : %d",s);
    return 0; 
}