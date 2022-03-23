#include <stdio.h>
int cas(){
    char ch;
    printf("Enter a charecter : ");
    scanf("%c",&ch);
    if(ch>=97 && ch<=122)
        return (ch);
    else
        return (ch+32);
}
int main(){
    int a = cas();
    printf("%c\n",a);
    return 0;
}