#include<stdio.h>
int main(){
    int n,i,m1,m2;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    if(ar[0]>ar[1]){
        m1=ar[0];m2=ar[1];
    }else{
        m2=ar[0];m1=ar[1];
    }
    for(i=2;i<n;i++){
        if(m1<ar[i]){
            m2=m1;
            m1=ar[i];
        }
        else if(m2<ar[i])
            m2=ar[i];
    }
    printf("Second Largest : %d\n",m2);
    return 0;
}
