#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int m,n,i,j,k,temp;
    printf("Enter the order of the matrix (M x N): ");
    scanf("%d%d",&m,&n);
    int **ar=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
        *(ar+i)=(int *)malloc(n*sizeof(int));

    printf("Enter Matrix Elements : \n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &ar[i][j]);

    //aranging rows in ascending order\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            for(k=j+1;k<n;k++)
                if(ar[i][j]>ar[i][k])
                    swap(&ar[i][j],&ar[i][k]);
                    
    
    //aranging the columns in descending order \n");
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
            for(k=i+1;k<m;k++)
                if(ar[i][j]<ar[k][j])
                    swap(&ar[i][j],&ar[k][j]);
     
    printf("Output :\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
    free(ar); return 0;
}