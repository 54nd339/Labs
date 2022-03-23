#include <stdio.h>
int main(){
    printf("Enter the lower limit:");
    int u; scanf("%d",&u);
    printf("Enter the upper limit:");
    int l; scanf("%d",&l);
    printf("Prime nos. b/w %d and %d is:\n",u,l);
    int sum = 0, c = 0;
    for (int i=u; i<=l; i++){
        int num = i, flag = 1;
        for (int j=2; j<=num/2; j++){
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