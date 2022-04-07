#include <stdio.h>
int main(){
    printf("Enter the lower limit : ");
    int l; scanf("%d",&l);
    printf("Enter the upper limit : ");
    int u; scanf("%d",&u);
    printf("Even nos. :\n");
    for(int i=l; i<=u; i++){
        if(i%2==0)
        printf("%d\n",i);
    }
    printf("Odd nos. :\n");
    for(int i=l;i<=u;i++){
        if(i%2!=0)
        printf("%d\n",i);
    }
    return 0;
}