#include <stdio.h>
int cas(){
    printf("Enter a charecter : ");
    char ch; scanf("%c",&ch);
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