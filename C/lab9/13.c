#include<stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n],b[n-1];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    enter:
    printf("Enter an index to be deleted : ");
    int p; scanf("%d",&p);
    if(p>=n || p<0) goto enter;

    for(int i=0; i<p; i++)
        b[i] = ar[i];
    for(int i=p; i<n-1; i++)
        b[i] = ar[i+1];
    for(int i=0; i<n-1; i++)
        printf("element at %d : %d\n",i+1,b[i]);
    return 0;
}