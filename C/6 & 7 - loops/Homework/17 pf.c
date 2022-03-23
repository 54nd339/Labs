#include <stdio.h>
int main() {
    printf("Enter a number : ");
    int n; scanf("%d",&n);
    int m = n;
    printf("Prime Factors of %d are:\n",n);
    for(int i=2; i<=m; i++){
        while(m%i == 0){
            m /= i;
            printf("%d\n",i);
        }
    }
    return 0;
}