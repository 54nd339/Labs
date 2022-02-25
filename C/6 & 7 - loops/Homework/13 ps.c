#include <stdio.h>
int main(){
    int n,i,j,c,num,flag;
    printf("Enter the no. of terms : ");
    scanf("%d",&n);
    printf("Series :\n");
    for (i=2,c=1;c<=n;i++){
        num=i,flag=1;
        for (j=2;j<=num/2;j++){
            if (num%j==0){
            flag = 0;
            break;
            }
        }
        if(flag){
        c++;
        printf("%d\n",num);
        }
    }
    return 0;
}
