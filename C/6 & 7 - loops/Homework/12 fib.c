#include <stdio.h>
int main() {
    printf("Enter the no. of terms : ");
    int n; scanf("%d",&n);
    printf("Fibonacci Series :\n");
    for(int i=1, a=1, b=1; i<=n; i++) {
        printf("%d\n",a);
        int c = b;
        b += a; a = c;
    }
    return 0;
}