#include <stdio.h>
int main(){
    printf("Enter an operator +,-,*,/,%% : ");
    char op; scanf("%c",&op);
    printf("Enter 2 operands : ");
    int m, n; scanf("%d %d",&m,&n);
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