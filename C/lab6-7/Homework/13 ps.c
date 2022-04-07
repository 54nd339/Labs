#include <stdio.h>
int main(){
    printf("Enter the no. of terms : ");
    int n; scanf("%d",&n);
    printf("Series :\n");
    for (int i=2, c=1; c<=n; i++){
        int num = i, flag = 1;
        for (int j=2; j<=num/2; j++){
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