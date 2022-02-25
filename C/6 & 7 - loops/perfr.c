#include <stdio.h>
int main(){
    int num,sum,i;
    printf("Perfect no.\n");
    for(num=2;num<=500;num++){
        sum=0;
        for(i=2;i<=num;i++){
            sum+=(!(num%i))*(num/i);
        }
        if (sum==num)
            printf("%d \n",num);
    }
    return 0;
}
