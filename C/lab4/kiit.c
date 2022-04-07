#include <stdio.h>
int main(){
    printf("Enter your class : ");
    int class; scanf("%d",&class);
    if(class > 12){
        printf("KIIT University Students\n");
        return 0;
    }
    printf("KIIT Students\n");
    return 0;
}