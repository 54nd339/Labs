#include <stdio.h>
int main(){
    printf("Enter a Lowercase charecter : ");
    char ch; scanf("%c",&ch);
    char c = (char)(ch-32);
    printf("%c in Upper case is %c\n",ch,c);
    return 0;
}