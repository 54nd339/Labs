#include <stdio.h>
int main(){
    int u,l,i,j,num,flag,sum=0,c=0;
    printf("Enter the lower limit:");
    scanf("%d",&u);
    printf("Enter the upper limit:");
    scanf("%d",&l);
    printf("Prime nos. b/w %d and %d is:\n",u,l);
    for (i=u;i<=l;i++){
        num=i,flag=1;
        for (j=2;j<=num/2;j++){
            if (num%j==0){
                flag = 0;
                break;
            }
        }
        if(flag){
        printf("%d is a prime number\n",num);
        //sum+=num;
        //c++;
        }
        //else
        //printf("%d is not a prime number\n",num);
    }
    //printf("no. of prime nos.: %d\n",c);
    //printf("sum: %d\n",sum);
    return 0;
}
