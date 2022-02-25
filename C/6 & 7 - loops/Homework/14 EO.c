#include <stdio.h>
int main(){
    int u,i,l;
    printf("Enter the lower limit : ");
    scanf("%d",&l);
    printf("Enter the upper limit : ");
    scanf("%d",&u);
    printf("Even nos. :\n");
    for(i=l;i<=u;i++){
        if(i%2==0)
        printf("%d\n",i);
    }
    printf("Odd nos. :\n");
    for(i=l;i<=u;i++){
        if(i%2!=0)
        printf("%d\n",i);
    }
    return 0;
}
