#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter a number : ");
    int n; scanf("%d",&n);
    int s = 0, c = 0;
    while(n != 0){
        int r = n%2;
        s += (r*pow(10,c++));
        n /= 2;
    }
    printf("Binary form : %d \n",s);
    return 0;
}