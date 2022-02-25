#include <stdio.h>
int main(){
    char ch,c;
    printf("Enter a Lowercase charecter : ");
    scanf("%c",&ch);
    c=(char)(ch-32);
    printf("%c in Upper case is %c\n",ch,c);
    return 0;
}
