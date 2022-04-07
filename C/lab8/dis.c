#include <stdio.h>
/*
void dis(){
    printf("= \n");
}

void dis2(){
    for(int i=1; i<=10; i++)
    printf("=\n");
}

void dis3(int n){
    for(int i=1; i<=n; i++)
    printf("=\n");
}
*/
void dis4(char ch, int n){
    for(int i=1; i<=n; i++)
        printf("%c",ch);
    printf("\n");
}

int main(){
    /*
    dis();

    for(int i=1;i<=3;i++)
    dis2();

    printf("Enter a no.");
    int n; scanf("%d",&n);
    dis3(n);
    */
    printf("Enter a charecter : ");
    char ch; scanf("%c",&ch);
    printf("Enter a no.");
    int n; scanf("%d",&n);
    dis4(ch,n);
    return 0;
}