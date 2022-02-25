#include <stdio.h>
int main(){
    int num,i,sum=0,count=0;
    for(i=1;i<=10;i++){
        printf("Enter a number : ");
        scanf("%d",&num);
        count+=(num%2);
        sum+=((num%2)*num);
    }
    printf("No. of odd nos. : %d\n",count);
    printf("Sum : %d\n",sum);
    return 0;
}
