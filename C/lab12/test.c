#include <stdio.h>
int main(){
    printf("Enter number of rows:");
    int r; scanf("%d",&r);
    printf("Enter number of columns:");
    int c; scanf("%d",&c);
    int arr[r][c], *p = arr[0][0];
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter element %d,%d: ",i,j);
            scanf("%d",(*(p+i)+j));
        }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%d\t",*((p+i*c)+j));
        printf("\n");
    }
    return 0;
}