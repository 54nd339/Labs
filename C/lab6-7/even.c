#include <stdio.h>
int main(){
    int num, sum=0, count=0;
    for(int i=1; i<=10; i++){
        printf("Enter a number : ");
        scanf("%d",&num);
        count += !(num%2);
        sum += (!(num%2))*num;
    }
    printf("No. of even nos. : %d\n",count);
    printf("Sum : %d\n",sum);
    printf("Average : %f\n",(float)sum/count);
    return 0;
}