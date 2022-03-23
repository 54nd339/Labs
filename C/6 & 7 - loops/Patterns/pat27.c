#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++){
        for (int j=65+i; j<65+n; j++)
            printf("%c",(char)j);
        printf("\n");
    }
    return 0;
}