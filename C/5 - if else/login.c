#include <stdio.h>
int main(){
    char u; int p;
    printf("Enter username : ");
    scanf("%c",&u);
    if (u=='S'){
        printf("Enter password : ");
        scanf("%d",&p);
        if (p==20051025)
            printf("Login Successful\n");
        else
            printf("Incorrect Password\n");
    }
    else
        printf("Wrong Username\n");
    return 0;
}
