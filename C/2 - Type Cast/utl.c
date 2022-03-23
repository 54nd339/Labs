#include <stdio.h>
int main(){
    printf("Enter an Uppercase charecter : \n");
    char ch; scanf("%c",&ch);
    char c=(char)(ch+32);
    printf("%c in Lower case is %c\n",ch,c);
    return 0;
}