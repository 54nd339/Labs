#include<stdio.h>
int main(){
    int n,i;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n],sq[n],cb[n],fact[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nOriginal Array : ");
    for(i=0;i<n;i++)
        printf("%d, ",ar[i]);
    
    for(i=0;i<n;i++)
        sq[i]=ar[i]*ar[i];
    printf("\nSquare Array : ");
    for(i=0;i<n;i++)
        printf("%d, ",sq[i]);
     
    for(i=0;i<n;i++)
        cb[i]=ar[i]*ar[i]*ar[i];
    printf("\nCube Array : ");
    for(i=0;i<n;i++)
        printf("%d, ",cb[i]);
        
    for(i=0;i<n;i++){
        int p=1;
        for(int j=2;j<=ar[i];j++)
        p*=j;
        fact[i]=p;
    }
    printf("\nFactorial Array : ");
    for(i=0;i<n;i++)
        printf("%d, ",fact[i]);
    return 0;
}
