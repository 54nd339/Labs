#include <stdio.h>
void swap(int m, int n){
    m += n; n = m-n; m -= n;
    printf("Swapped value : \t");
    printf("a=%d, b=%d \n",m,n);
}
int main(){
    printf("Enter 2 integers : ");
    int a, b; scanf("%d%d",&a,&b);
    printf("Original value : \t");
    printf("a : %d, b : %d \n",a,b);
    swap(a, b);
    return 0;
}