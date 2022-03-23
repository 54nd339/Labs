#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter number of rows : ");
    int r; scanf("%d",&r);
    printf("Enter number of columns : ");
    int c; scanf("%d",&c);
    int (*p)[c], sum = 0;
    p = (int(*)[c])malloc(r*c*sizeof(int));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter element %d,%d : ",i+1,j+1);
            scanf("%d",(*(p+i)+j));
            sum += *(*(p+i)+j);
        }
    printf("Sum of the elements : %d\n",sum);
    return 0;
}