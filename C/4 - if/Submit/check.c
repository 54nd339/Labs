#include <stdio.h>
int main(){
    printf("Enter a charecter : ");
    char ch; scanf("%c",&ch);
    int a = ch;
    if(((a>=97) && (a<=122)) || ((a>=65) && (a<=90))){
        if((ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u')
        || (ch=='A') || (ch=='E') || (ch=='I') || (ch=='O') || (ch=='U')){
            printf("%c is vowel\n",ch);
            return 0;
        }
        printf("%c is consonant\n",ch);
        return 0;
    }
    printf("It is not an alphabet\n");
    return 0;
}