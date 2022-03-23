#include <stdio.h>
int main(){
    printf("Perfect no.\n");
    for(int num=2; num<=500; num++){
        int sum=0;
        for(int i=2;i<=num;i++){
            sum+=(!(num%i))*(num/i);
        }
        if (sum==num)
            printf("%d \n",num);
    }
    return 0;
}