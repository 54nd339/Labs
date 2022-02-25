#include <stdio.h>
int main(){
    int r,c,i,j;
    printf("Enter number of rows:");
    scanf("%d",&r);
    printf("Enter number of columns:");
    scanf("%d",&c);
    int arr[r][c];
    int *p=arr[0][0];
    
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            printf("Enter element %d,%d: ",i,j);
            scanf("%d",(*(p+i)+j));
        }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d\t",*((p+i*c)+j));
            printf("\n");
    }
    return 0;
}
