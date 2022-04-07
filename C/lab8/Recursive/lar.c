#include <stdio.h>
int fmaxi(int n){
    int max = 0, m;
    for(int i=1; i<=n; i++){
        printf("Enter a no. : ");
        scanf("%d",&m);
        if(max < m)
            max = m;
    }
    return max;
}
int main(){
    printf("Enter the no. of nos. to be entered : ");
    int n; scanf("%d",&n);
    printf("max : %d",fmaxi(n));
    return 0;
}