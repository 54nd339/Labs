 #include <stdio.h>
int fact(int n){
    return n==0 ? 1 : n*fact(n-1);
}
int main(){
    printf("Enter a no. : ");
    int n; scanf("%d",&n);
    printf("Factorial : %d",fact(n));
    return 0;
}