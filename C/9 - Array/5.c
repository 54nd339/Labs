#include<stdio.h>
int main(){
    int n,i,j,count;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Unique elements in the array : ");
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++)
            if(ar[i]==ar[j])
                count++;
        if(count-1==0)
        printf("%d ",ar[i]);
    }
    return 0;
}
