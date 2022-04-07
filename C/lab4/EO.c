#include <stdio.h>
int main(){
    printf("Enter an integer : ");
    int n; scanf("%d",&n);
    if(n%2 == 0){
        printf("%d is even\n",n);
        return 0;
    }
    printf("%d is odd\n",n);
    return 0;
}