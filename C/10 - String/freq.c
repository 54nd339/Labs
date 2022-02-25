#include <stdio.h>
int main(){
    char str[100],ch;
    int i=0, c=0;
    printf("Enter a String: ");
    //scanf("%[^\n]s",str);
    //getchar();
    gets(str);
    printf("Enter a charecter to find frequency: ");
    scanf("%c",&ch);
    while(c+=(ch==str[i]),str[i++]);
        printf("Frequency of %c is : %d\n",ch,c);
    return 0;
}
