#include <stdio.h>
#include <math.h>
void dec2Bin(int n){
    int s = 0, c = 0;
    while(n != 0){
        int r = n%2;
        s += (r*(int)pow(10,c));
        c++; n /= 2;
    }
    printf("Decimal Equivalent : %d",s);
}

void bin2Dec(int n){
    int s=0, c=0;
    while(n != 0){
        int r = n%10;
        s += (r*(int)pow(2,c));
        c++; n /= 10;
    }
    printf("Binary Equivalent : %d",s);
}

int main(){
    printf("Enter 1 for Decimal to Binary\n");
    printf("Enter 2 for Binary to Decimal\n");
    int n; scanf("%d",&n);
    if(n == 1){
        printf("Enter a decimal no. : ");
        int m; scanf("%d",&m);
        dec2Bin(m);
    }
    else if(n == 2){
        printf("Enter a Binary no. : ");
        int m; scanf("%d",&m);
        bin2Dec(m);
    }
    else
        printf("Wrong input");
}