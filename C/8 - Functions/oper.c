#include <stdio.h>
int main(){
    char op; int m,n;
    printf("Enter an operator +,-,*,/,%%");
    scanf("%c",&op);
    printf("Enter 2 operands:");
    scanf("%d %d",&m,&n);
    switch(op){
        case '+':
            printf("%d + %d = %d",m,n,(m+n));
            break;
        case '-':
            printf("%d - %d = %d",m,n,(m-n));
            break;
        case '*':
            printf("%d * %d = %d",m,n,(m*n));
            break;
        case '/':
            printf("%d / %d = %f",m,n,(double)m/n);
            break;
        case '%':
            printf("%d %% %d = %d",m,n,(m%n));
            break;
        default:
            printf("Wrong inputs");
            break;
    }
    return 0;
}
