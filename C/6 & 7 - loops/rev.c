#include <stdio.h>
int main(){
    int num, out=0;
    printf("Enter a number : ");
    scanf("%d",&num);
    int in = num;
    while (in%10 != 0){
        out = (in%10) + out*10;
        in /= 10;
    }
    printf("reverse of %d : %d\n",num,out);
}