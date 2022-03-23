#include <stdio.h>
#include <math.h>
int main() {
    printf("Enter the no. of terms : ");
    int n; scanf("%d",&n);
    printf("Series:\n");
    for(int i=1, a=1, c=1; i<=n; i++) {
        printf("%d\n",a);
        a += pow(2,c++);
    }
    return 0;
}