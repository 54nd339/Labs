#include <stdio.h>
int main(){
    int num,in,out=0,sum=0;
    printf("Enter a number : ");
    scanf("%d",&num);
    in=num;
    while (in%10!=0){
        sum+=(in%10);
        out=(in%10)+out*10;
        in/=10;
    }
    printf("Sum of the digits of %d is %d\n",num,sum);
    if (num==out)
        printf("%d is palindrome\n",num);
    else
        printf("%d is not palindrome \n reversed no.: %d",num,out);
}
