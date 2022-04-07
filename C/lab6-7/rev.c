#include <stdio.h>
int main(){
    printf("Enter a number : ");
    int num; scanf("%d",&num);
    int in = num, out = 0;
    while (in%10 != 0){
        out = (in%10) + out*10;
        in /= 10;
    }
    printf("reverse of %d : %d\n",num,out);
}