#include<stdio.h>
int main(){
    int n,i,j,t,m,p;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n],b[n-1];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter an index to be deleted : ");
    scanf("%d",&p);
    for(i=0;i<p-1;i++)
    b[i]=ar[i];
    b[p]=m;
    for(i=p-1;i<n;i++)
    b[i]=ar[i+1];

    for(i=0;i<n-1;i++)
    printf("element at %d : %d\n",i+1,b[i]);
    return 0;
}
