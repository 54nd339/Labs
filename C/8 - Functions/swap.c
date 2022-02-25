#include <stdio.h>
void swap(int m, int n){
    m=m+n;n=m-n;m=m-n;
    printf("Swapped value: \t");
    printf("a=%d, b=%d \n",m,n);
}
int main(){
    int a, b;
    printf("Enter 2 integers:");
    scanf("%d%d",&a,&b);
    printf("Original value: \t");
    printf("a=%d, b=%d \n",a,b);
    swap(a,b);
    return 0;
}
