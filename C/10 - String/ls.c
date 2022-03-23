#include <stdio.h>
void read(int *a, int num){
    for(int i=0; i<num; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",a+i);
    }
}
int lar(int *a, int *b, int num){
    int s1=0, s2=0;
    for(int i=0; i<num; i++){
        s1 += a[i]; s2 += b[i];
    }
    return s1==s2 ? 0 : s1>s2 ? 1 : 2;
}
int main(){
    int *p, *q, n;
    printf("Enter number of element in each array:");
    scanf("%d",&n);
    int x[n], y[n];
    p = x; q = y;
    
    printf("Enter 1st array:\n");
    read(p,n);
    printf("Enter 2nd array:\n");
    read(q,n);
    
    int g = lar(p,q,n);
    if(!g)    
        printf("Both sum are equal\n");
    else if(g==1) 
        printf("sum of 1st is larger than that of 2nd\n");
    else          
        printf("sum of 2nd is larger than that of 1st\n");
    return 0;
}