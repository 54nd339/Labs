#include <stdio.h>
int main(){
    int m=0,n=0,p=0,q=0,i,j;
    printf("Enter the no. of rows of 1st matrix : ");
    scanf("%d",&m);
    printf("Enter the no. of columns of 1st matrix : ");
    scanf("%d",&n);
    int fir[m][n];
    printf("\nEnter the Elements of the matrix :\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            printf("Enter Element %d,%d : ",i+1,j+1);
            scanf("%d",&fir[i][j]);
        }
            
    printf("\nEnter the no. of rows of 2nd matrix : ");
    scanf("%d",&p);
    printf("Enter the no. of columns of 2nd matrix:");
    scanf("%d",&q);
    int sec[p][q];
    printf("\nEnter the Elements of the matrix :\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++){
            printf("Enter Element %d,%d : ",i+1,j+1);
            scanf("%d",&sec[i][j]);
        }
        
    if(n!=p)
        printf("\nProduct not possible\n");
    else{
        int pro[m][q];
        for(i=0;i<m;i++)
            for(j=0;j<q;j++){
                pro[i][j]=0;
                for(int k=0;k<p;k++)
                    pro[i][j]+=fir[i][k]*sec[k][j];
            }
        printf("\nproduct :\n");
        for(i=0;i<m;i++){
            for(j=0;j<q;j++)
                printf("%d\t",pro[i][j]);
            printf("\n");
        }
    }
    return 0;
}
