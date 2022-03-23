#include <stdio.h>
int main(){
    printf("Enter a Lowercase charecter : ");
    char ch; scanf("%c",&ch);
    int a = ch;
    if((a>=97) && (a<=122)){
        char c=(char)(ch-32);
        printf("%c in Upper case is %c\n",ch,c);
        return 0;
    }
    printf("%c is in Upper case\n",ch);
    return 0;
}