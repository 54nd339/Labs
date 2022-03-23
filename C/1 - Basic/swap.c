#include <stdio.h>
int main(){
    int a, b, c;
    printf("Enter 2 integers : ");
    scanf("%d%d",&a,&b);
    printf("Original value : \t");
    printf("a : %d, b : %d \n",a,b);
    c = b; b = a; a = c;
    printf("Swapped value : \t");
    printf("a : %d, b : %d \n",a,b);
    return 0;
}