#include <stdio.h>
int reverse(int n, int temp){
    if(n==0) return temp;
    temp = temp*10 + (n%10);
    return reverse(n/10,temp);
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf(reverse(x,0) == x ? "Palindrome" : "Not Palindrome");
    return 0; 
}