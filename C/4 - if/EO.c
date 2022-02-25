#include <stdio.h>
int main(){
    int n;
    printf("Enter an integer : ");
    scanf("%d",&n);
    if(n%2==0){
        printf("%d is even\n",n);
        return 0;
    }
    printf("%d is odd\n",n);
    return 0;
}
