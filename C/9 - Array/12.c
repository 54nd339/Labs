#include<stdio.h>
int main(){
    int n,i,j,t,m,p;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n],b[n+1];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nAscending order: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(ar[j]>ar[i]){
              t=ar[i];
              ar[i]=ar[j];
              ar[j]=t;  
            }
    
    printf("Enter a point : ");
    scanf("%d",&p);
    printf("Enter element to be entered: ");
    scanf("%d",&m);
    for(i=0;i<p;i++)
    b[i]=ar[i];
    b[p]=m;
    for(i=p;i<n;i++)
    b[i+1]=ar[i];

    for(i=0;i<=n;i++)
    printf("element at %d : %d\n",i,b[i]);
    return 0;
}
