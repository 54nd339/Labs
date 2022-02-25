#include <stdio.h>
int main(){
    int a;
    printf("Enter value of a : ");
    scanf("%d",&a);
    if (a<0)
        printf("decceleration\n");
    else if (a==0)
        printf("Constant velocity\n");
    else
        printf("acceleration\n");
    return 0;
}
