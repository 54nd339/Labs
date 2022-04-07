#include <stdio.h>
int main(){
    printf("Enter username : ");
    char u; scanf("%c",&u);
    if (u == 'S'){
        printf("Enter password : ");
        int p; scanf("%d",&p);
        if (p == 20051025)
            printf("Login Successful\n");
        else
            printf("Incorrect Password\n");
    }
    else
        printf("Wrong Username\n");
    return 0;
}