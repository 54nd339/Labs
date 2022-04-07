#include <stdio.h>
int main(){
    char str[100];
    int i = -1;
    printf("Enter a String : ");
    scanf("%s",str);
    while(str[++i]);
        printf("Length of string : %d\n",i);
    return 0;
}