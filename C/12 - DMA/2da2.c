#include <stdio.h>
#include<stdlib.h>
int main(){
    int r,c,i,j,sum=0;
    printf("Enter number of rows : ");
    scanf("%d",&r);
    printf("Enter number of columns : ");
    scanf("%d",&c);
    int (*p)[c];
    p=(int(*)[c])malloc(r*c*sizeof(int));
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            printf("Enter element %d,%d : ",i+1,j+1);
            scanf("%d",(*(p+i)+j));
            sum+=*(*(p+i)+j);
        }
    printf("Sum of the elements : %d\n",sum);
    return 0;
}
