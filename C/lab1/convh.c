#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter time in second : ");
    int s; scanf("%d",&s);
    printf("Amount : %d Hour, %d Minute, %d second", s/3600, ((s%3600)/60), ((s%3600)%60));
    return 0;
}