#include <stdio.h>
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    int i=-1, ar[10], s=0;
    while(x){
        ar[++i] = x%10;
        x /= 10;
    }
    while(i >= 0){
        s = s*10 + ar[i];
        i -= 2;
    }
    printf("Output : %d",s);
    return 0; 
}