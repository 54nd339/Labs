#include <stdio.h>
int main(){
    char ch,c;
    printf("Enter an Uppercase charecter : \n");
    scanf("%c",&ch);
    c=(char)(ch+32);
    printf("%c in Lower case is %c\n",ch,c);
    return 0;
}
