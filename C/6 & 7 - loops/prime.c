#include <stdio.h>
int main(){
    int num, flag=1;
    printf("Enter a number : ");
    scanf("%d",&num);
    for (int i=2; i<=num/2; i++){
        if (num%i == 0){
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("%d is a prime number\n",num);
    else
        printf("%d is not a prime number\n",num);
}