#include <stdio.h>
int main(){
    int age;
    printf("Enter your age : ");
    scanf("%d",&age);
    if(age<18){
        printf("Not eligible to vote");
        return 0;
    }
    printf("Eligible to vote");
    return 0;
}
