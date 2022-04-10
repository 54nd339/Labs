#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    int c = (int)log10(x);
    int i = 0, s = 0;
    while(c >= 0){
        if(c%2 == 0)
            s += (x%10)*pow(10,i++);
        c--; x /= 10;
    }
    printf("Output : %d",s);
    return 0; 
}