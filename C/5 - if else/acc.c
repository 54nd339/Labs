#include <stdio.h>
int main(){
    printf("Enter value of a : ");
    int a; scanf("%d",&a);
    if (a<0)
        printf("decceleration\n");
    else if (a==0)
        printf("Constant velocity\n");
    else
        printf("acceleration\n");
    return 0;
}