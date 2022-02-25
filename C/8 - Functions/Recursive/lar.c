#include <stdio.h>
int fmaxi(int n){
    int max=0,m;
    for(int i=1;i<=n;i++){
        printf("Enter a no. : ");
        scanf("%d",&m);
        if(max<m)
            max=m;
    }
    return max;
}
int main(){
    int n;
    printf("Enter the no. of nos. to be entered : ");
    scanf("%d",&n);
    printf("max : %d",fmaxi(n));
    return 0;
}
